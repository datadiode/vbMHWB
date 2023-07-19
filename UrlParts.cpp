// UrlParts.cpp: implementation of the CUrlParts class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UrlParts.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUrlParts::CUrlParts()
{
	szScheme = NULL;
	szHostName = NULL;
	szUserName = NULL;
	szPassword = NULL;
	szUrlPath = NULL;
	szExtraInfo = NULL;
	szFileName = NULL;
	szFileExtension = NULL;
	dwScheme = 0;
	dwHostName = 0;
	dwUserName = 0;
	dwPassword = 0;
	dwUrlPath = 0;
	dwExtraInfo = 0;
	dwFileName = 0;
	dwFileExtension = 0;
	dwPort = 0;
	lnScheme = INTERNET_SCHEME_DEFAULT;
}

CUrlParts::~CUrlParts()
{
	ResetBuffers();
}

void CUrlParts::ResetBuffers()
{
	if(szScheme)
	{
		free(szScheme);
		szScheme = NULL;
		szHostName = NULL;
		szUserName = NULL;
		szPassword = NULL;
		szUrlPath = NULL;
		szExtraInfo = NULL;
		szFileName = NULL;
		szFileExtension = NULL;
		dwScheme = 0;
		dwHostName = 0;
		dwUserName = 0;
		dwPassword = 0;
		dwUrlPath = 0;
		dwExtraInfo = 0;
		dwFileName = 0;
		dwFileExtension = 0;
		dwPort = 0;
	}
}

bool CUrlParts::AllocateBuffers(int iNum)
{
	ResetBuffers();
	LPTSTR lpstrHeap = szScheme = (LPTSTR) malloc((iNum + 1) * sizeof(TCHAR) * 8);
	//Check
	if(!szScheme)
		return false;
	szHostName = lpstrHeap += (iNum + 1);
	szUserName = lpstrHeap += (iNum + 1);
	szPassword = lpstrHeap += (iNum + 1);
	szUrlPath = lpstrHeap += (iNum + 1);
	szExtraInfo = lpstrHeap += (iNum + 1);
	szFileName = lpstrHeap += (iNum + 1);
	szFileExtension = lpstrHeap += (iNum + 1);
	szScheme[iNum] = _T('\0');
	szHostName[iNum] = _T('\0');
	szUserName[iNum] = _T('\0');
	szPassword[iNum] = _T('\0');
	szUrlPath[iNum] = _T('\0');
	szExtraInfo[iNum] = _T('\0');
	szFileName[iNum] = _T('\0');
	szFileExtension[iNum] = _T('\0');
	return true;
}

bool CUrlParts::SplitUrl(BSTR bUrl)
{
	if(bUrl == NULL)
		return false;

	DWORD ilen = ::SysStringLen(bUrl);
	if(ilen == 0)
		return false;
	//Allocate buffers
	if(AllocateBuffers(ilen) == false)
		return false;

	URL_COMPONENTS URLComponentsOut;
	ZeroMemory(&URLComponentsOut, sizeof(URLComponentsOut));
	URLComponentsOut.dwStructSize = sizeof(URLComponentsOut);

	URLComponentsOut.lpszScheme = szScheme;         // pointer to scheme name
	URLComponentsOut.dwSchemeLength = ilen;         // length of scheme name

	URLComponentsOut.lpszHostName = szHostName;     // pointer to host name
	URLComponentsOut.dwHostNameLength = ilen;       // length of host name

	URLComponentsOut.lpszUserName = szUserName;     // pointer to user name
	URLComponentsOut.dwUserNameLength = ilen;       // length of user name

	URLComponentsOut.lpszPassword = szPassword;     // pointer to password
	URLComponentsOut.dwPasswordLength = ilen;       // length of password

	URLComponentsOut.lpszUrlPath = szUrlPath;       // pointer to URL-path
	URLComponentsOut.dwUrlPathLength = ilen;        // length of URL-path

	URLComponentsOut.lpszExtraInfo = szExtraInfo;   // pointer to extra information (e.g. ?foo or #foo)
	URLComponentsOut.dwExtraInfoLength = ilen;      // length of extra information
//Flags
	DWORD dwFlags = ICU_DECODE;

//0 default
	//Return as is
//1 ICU_DECODE Converts encoded characters back to their normal form.
	//This can be used only if the user provides buffers in the URL_COMPONENTS structure to copy the components into.
//8 ICU_ESCAPE Converts all escape sequences (%xx) to their corresponding characters.
	//This can be used only if the user provides buffers in the URL_COMPONENTS structure to copy the components into.

	//If the pointer contains the address of the user-supplied buffer,
	//the length member must contain the size of the buffer.
	//InternetCrackUrl copies the component into the buffer, and
	//the length member is set to the length of the copied component, minus 1
	//for the trailing string terminator.
	USES_CONVERSION;
	if(!InternetCrackUrl(OLE2T(bUrl), 0, dwFlags, &URLComponentsOut))
		return false;

	dwScheme = URLComponentsOut.dwSchemeLength;
	dwHostName = URLComponentsOut.dwHostNameLength;
	dwUserName = URLComponentsOut.dwUserNameLength;
	dwPassword = URLComponentsOut.dwPasswordLength;
	dwUrlPath = URLComponentsOut.dwUrlPathLength;
	dwExtraInfo = URLComponentsOut.dwExtraInfoLength;

	lnScheme = URLComponentsOut.nScheme;

	if(dwUrlPath > 0)
	{
		//Look for filename here
		TCHAR *lpStr1 = szUrlPath;
		lpStr1 += _tcslen(lpStr1);
		while ((lpStr1 > szUrlPath) && (*lpStr1 != _T('/')) && (*lpStr1 != _T('\\')))
		{
			//Look for extension at the same time

			//if not using ICU_DECODE flag in InternetCrackUrl function,
			//Watch out for decoded charcters,"%2E" -> "."

			//(dwFileExtension == 0),
			//To avoid abc.somesite.com.mpg style of file naming

			if( (*lpStr1 == _T('.')) && (dwFileExtension == 0) )
			{
				dwFileExtension = _tcslen(lpStr1);
				if(dwFileExtension > 0)
				{
					memcpy(szFileExtension, lpStr1, dwFileExtension * sizeof(TCHAR) );
					szFileExtension[dwFileExtension] = _T('\0');
				}
			}
			--lpStr1;
		}
		if ((*lpStr1 == _T('/')) || (*lpStr1 == _T('\\')))
			lpStr1++;
		dwFileName = _tcslen(lpStr1);
		if(dwFileName > 0)
		{
			memcpy(szFileName, lpStr1, dwFileName * sizeof(TCHAR));
			szFileName[dwFileName] = _T('\0');
		}
	}
	dwPort = URLComponentsOut.nPort;
	return true;
}
