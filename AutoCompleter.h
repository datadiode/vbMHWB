#pragma once

#include <shldisp.h>
#include <shlguid.h>

//For ShellAutoComplete method to load SHLWAPI.DLL
typedef HRESULT (WINAPI *SHAUTOCOMPLETEFN) (HWND hTarget, DWORD dwFlags);

class CAutoCompleter : public IEnumString
{
private:

	CSimpleArray<LPWSTR> m_asList;
	CComPtr<IAutoComplete> m_pac;

	ULONG m_nCurrentElement;
	ULONG m_nRefCount;
	BOOL m_fBound;
	HWND m_hwndEdit;
	HWND m_hwndParent;

public:
	// Constructors/destructors

	CAutoCompleter()
	{
		InternalInit();
	}

	~CAutoCompleter()
	{
		DeleteAllItems();
	}

	const HWND GetEditHwnd()
	{
		return m_hwndEdit;
	}

	const HWND GetParentEditHwnd()
	{
		return m_hwndParent;
	}

	static HRESULT ShellAutoComplete(HWND hwndTarget, BOOL bIsCombo, DWORD dwFlags)
	{
		HRESULT ret = S_FALSE;
		if( (hwndTarget == NULL) || (!::IsWindow(hwndTarget)) )
			return ret;

		HWND hwndEdit = NULL;
		if(bIsCombo)
		{
			hwndEdit = ::FindWindowEx(hwndTarget, NULL, _T("EDIT"), NULL);
		}
		else
			hwndEdit = hwndTarget;

		if(!::IsWindow(hwndEdit))
			return ret;
		
		HINSTANCE hSHLWAPIDLL = ::LoadLibrary(_T("SHLWAPI.DLL"));
		if (!hSHLWAPIDLL)
			return ret;

		SHAUTOCOMPLETEFN pSHAC = 
			(SHAUTOCOMPLETEFN)GetProcAddress(hSHLWAPIDLL, 
			"SHAutoComplete");

		if (pSHAC != NULL)
		{
			ret = SUCCEEDED(pSHAC(hwndEdit, dwFlags));
		}

		::FreeLibrary(hSHLWAPIDLL);

		return ret;
	}

	BOOL AddItem(unsigned short *pItem, UINT istrLen = 0) // ==  LPWSTR LPOLESTR BSTR
	{
		UINT ilen = istrLen;

		if(ilen == 0)
			ilen = wcslen(pItem);
		LPWSTR szTmp = (LPWSTR) malloc((ilen + 1) * sizeof(WCHAR));
		//memset(szTmp, 0, ((ilen+1) * sizeof(WCHAR)));
		if(szTmp)
		{
			//wcsncpy
			wcscpy(szTmp, pItem);
			szTmp[ilen] = (WCHAR)NULL;
			return m_asList.Add(szTmp);
		}
		else
			return FALSE;
	}

	BOOL DeleteAllItems()
	{
		BOOL bRet = TRUE;
		
		int isize = m_asList.GetSize();
		if(isize == 0)
			return bRet;

		for(int i = 0; i < isize; i++)
		{
			if(m_asList[i] != NULL)
				free(m_asList[i]);
			m_asList[i] = NULL;
		}
		m_asList.RemoveAll();
		return bRet;
	}

	int GetItemCount()
	{
		return m_asList.GetSize();
	}

	BOOL Disable()
	{
		if ((!m_pac) || (!m_fBound))
			return FALSE;
		return SUCCEEDED(EnDisable(FALSE));
	}

	BOOL Enable(VOID)
	{
		if ((!m_pac) || (m_fBound))
			return FALSE;
		return SUCCEEDED(EnDisable(TRUE));
	}

	//For example, set p_lpszFormatString to "http://www. %s.com/".
	//When a user enters "MyURL" into the edit box and presses CTRL+ENTER,
	//the text in the edit box is updated to "http://www.MyURL.com/".

	BOOL Bind(HWND p_hWndEdit, BOOL IsControlCombo = FALSE, DWORD p_dwOptions = 0, LPCTSTR p_lpszFormatString = NULL)
	{
		ATLASSERT(::IsWindow(p_hWndEdit));
		if ((m_fBound) || (m_pac))
			return FALSE;

		//HWND hEdit = NULL;		
		if(IsControlCombo)
		{
			m_hwndEdit = ::FindWindowEx(p_hWndEdit, NULL, _T("EDIT"), NULL);
			if(!::IsWindow(m_hwndEdit))
				return FALSE;
			m_hwndParent = p_hWndEdit;
		}
		else
		{
			m_hwndEdit = p_hWndEdit;
			m_hwndParent = NULL; //m_hwndParent = ::GetParent(m_hwndEdit);
		}

		HRESULT hr = m_pac.CoCreateInstance(CLSID_AutoComplete);
		if (SUCCEEDED(hr))
		{
			USES_CONVERSION;
			hr = m_pac->Init(m_hwndEdit, this, NULL, T2COLE(p_lpszFormatString));
			if(!SUCCEEDED(hr))
				return FALSE;
		
			if (p_dwOptions)
			{
				CComQIPtr<IAutoComplete2> pAC2(m_pac);
				ATLASSERT(pAC2);
				pAC2->SetOptions(p_dwOptions);			// This never fails?
				//pAC2.Release();
			}

			m_fBound = TRUE;
			return TRUE;
		}
		return FALSE;
	}

	VOID Unbind()
	{
		if (!m_fBound)
			return;
		ATLASSERT(m_pac);
		if (m_pac)
		{
			m_pac.Release();
			m_fBound = FALSE;
			m_hwndEdit = NULL;
			m_hwndParent = NULL;
		}
	}

public:
	//	IUnknown implementation

	STDMETHODIMP_(ULONG) AddRef()
	{
		return ++m_nRefCount;
	}

	STDMETHODIMP_(ULONG) Release()
	{
		if(--m_nRefCount == 0)
		{
			delete this;
			return 0;
		}
		return m_nRefCount;
	}

	STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject)
	{
		HRESULT hr = E_NOINTERFACE;
		if (ppvObject != NULL)
		{
			*ppvObject = NULL;

			if (IID_IUnknown == riid)
				*ppvObject = (IUnknown *)this;

			if (IID_IEnumString == riid)
				*ppvObject = (IEnumString *)this;

			if (*ppvObject != NULL)
			{
				hr = S_OK;
				AddRef();
			}
		}
		else
		{
			hr = E_POINTER;
		}
		return hr;
	}


	//
	//	IEnumString implementation
	//

	STDMETHODIMP Next(ULONG celt, LPOLESTR* rgelt, ULONG* pceltFetched)
	{

		HRESULT hr = S_FALSE;

		if (!celt)
			celt = 1;

		ULONG i;
		for (i = 0; i < celt; i++)
		{

			if (m_nCurrentElement == (ULONG)m_asList.GetSize())
				break;
			int ilen = wcslen(m_asList[m_nCurrentElement]);
			rgelt[i] = (LPOLESTR)::CoTaskMemAlloc((ULONG) sizeof(WCHAR) * (ilen + 1));
			//memset(rgelt[i], 0, ((ilen+1) * sizeof(WCHAR)));
			if(rgelt[i])
			{
				wcscpy(rgelt[i], m_asList[m_nCurrentElement]);
				rgelt[i][ilen] = (OLECHAR)NULL;
			}

			if(pceltFetched)
				*pceltFetched++;
			
			m_nCurrentElement++;
		}

		if (i == celt)
			hr = S_OK;

		return hr;
	}
 
	STDMETHODIMP Skip(ULONG celt)
	{
		
		m_nCurrentElement += celt;
		
		if (m_nCurrentElement > (ULONG)m_asList.GetSize())
			m_nCurrentElement = 0;

		return S_OK;
	}
 
	STDMETHODIMP Reset(void)
	{
		m_nCurrentElement = 0;
		return S_OK;
	}
 
	STDMETHODIMP Clone(IEnumString** ppenum)
	{
		if (!ppenum)
			return E_POINTER;
		
		CAutoCompleter* pnew = new CAutoCompleter();
		pnew->AddRef();
		*ppenum = pnew;
		return S_OK;
	}

private:
	// Internal implementation
	void InternalInit()
	{
		m_nCurrentElement = 0;
		m_nRefCount = 0;
		m_fBound = FALSE;
		m_hwndEdit = NULL;
		m_hwndParent = NULL;
	}

	HRESULT EnDisable(BOOL p_fEnable)
	{
		HRESULT hr = S_OK;
		ATLASSERT(m_pac);
		hr = m_pac->Enable(p_fEnable);
		if (SUCCEEDED(hr))
			m_fBound = p_fEnable;
		return hr;
	}
};