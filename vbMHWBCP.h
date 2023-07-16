#ifndef _VBMHWBCP_H_
#define _VBMHWBCP_H_
#include "ATLCPImplMT.h"

//Do not use the wizard to update this file
//You will end up with many compile errors - too many

template <class T>
class CProxy_IvbWBEvents : public IConnectionPointImplMT<T, &DIID__IvbWBEvents, CComDynamicUnkArray>
{
public:
	VOID Fire_StatusTextChange(SHORT wbUID, BSTR Text)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Text;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ProgressChange(SHORT wbUID, LONG Progress, LONG ProgressMax)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = Progress;
				pvars[0] = ProgressMax;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_CommandStateChange(SHORT wbUID, LONG Command, VARIANT_BOOL Enable)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = Command;
				pvars[0] = Enable;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_DownloadBegin(SHORT wbUID)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = wbUID;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_DownloadComplete(SHORT wbUID)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = wbUID;
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_TitleChange(SHORT wbUID, BSTR Text)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Text;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_PropertyChange(SHORT wbUID, BSTR szProperty)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = szProperty;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x7, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_BeforeNavigate2(SHORT wbUID, VARIANT * URL, IDispatch * pDisp, VARIANT * Flags, VARIANT * TargetFrameName, VARIANT * PostData, VARIANT * Headers, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[8];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[7] = wbUID;	//VT_I2

				pvars[6].vt = VT_BYREF|VT_VARIANT;
				pvars[6].byref = URL;		//VT_BSTR
				
				pvars[5] = pDisp;	//VT_DISPATCH
				
				pvars[4].vt = VT_BYREF|VT_VARIANT;
				pvars[4].byref = Flags;
				
				pvars[3].vt = VT_BYREF|VT_VARIANT;
				pvars[3].byref = TargetFrameName;

				pvars[2].vt = VT_BYREF|VT_VARIANT;
				pvars[2].byref = PostData;

				pvars[1].vt = VT_BYREF|VT_VARIANT;
				pvars[1].byref = Headers;
				
				pvars[0].vt = VT_BOOL | VT_BYREF;
				pvars[0].byref = Cancel;
				DISPPARAMS disp = { pvars, NULL, 8, 0 };
				pDispatch->Invoke(0x8, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_NewWindow2(SHORT wbUID, IDispatch * * ppDisp, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;

				pvars[1].vt = VT_BYREF|VT_DISPATCH;
				pvars[1].byref = ppDisp;
				
				pvars[0].vt = VT_BOOL|VT_BYREF;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x9, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
 	VOID Fire_NavigateComplete2(SHORT wbUID, VARIANT * URL, IDispatch * pDisp)
 	{
 		//T* pT = static_cast<T*>(this);
 		int nConnectionIndex;
 		CComVariant* pvars = new CComVariant[3];
 		int nConnections = m_vec.GetSize();
 		
 		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
 		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

 			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
 			if (pDispatch != NULL)
 			{
 				pvars[2] = wbUID;
 				//pvars[1] = URL;

				pvars[1].vt = VT_BYREF|VT_VARIANT;
				pvars[1].byref = URL;		//VT_BSTR
 				//This causes VB to crash after removng a WB
 				//pvars[0].vt = VT_DISPATCH;
 				//pvars[0].pdispVal = pDisp;
 				pvars[0] = pDisp;	//VT_DISPATCH
 
 				DISPPARAMS disp = { pvars, NULL, 3, 0 };
 				pDispatch->Invoke(0xa, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
 			}
 		}
 		delete[] pvars;
 	
 	}
 	VOID Fire_DocumentComplete(SHORT wbUID, VARIANT * URL, IDispatch * pDisp, VARIANT_BOOL isTopLevel)
 	{
 		//T* pT = static_cast<T*>(this);
 		int nConnectionIndex;
 		CComVariant* pvars = new CComVariant[4];
 		int nConnections = m_vec.GetSize();
 		
 		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
 		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

 			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
 			if (pDispatch != NULL)
 			{
 				pvars[3] = wbUID;
				pvars[2].vt = VT_BYREF|VT_VARIANT;
				pvars[2].byref = URL;		//VT_BSTR
 				pvars[1] = pDisp;	//VT_DISPATCH
 				pvars[0] = isTopLevel;
 				DISPPARAMS disp = { pvars, NULL, 4, 0 };
 				pDispatch->Invoke(0xb, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
 			}
 		}
 		delete[] pvars;
 	}
	VOID Fire_NavigateError(SHORT wbUID, IDispatch * pDisp, VARIANT * URL, VARIANT * TargetFrameName, VARIANT * StatusCode, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = wbUID;
				pvars[4] = pDisp;	//VT_DISPATCH
				
				pvars[3].vt = VT_BYREF|VT_VARIANT;
				pvars[3].byref = URL; //VARIANT structure of type VT_BSTR
				
				pvars[2].vt = VT_BYREF|VT_VARIANT;
				pvars[2].byref = TargetFrameName; //VARIANT structure of type VT_BSTR

				pvars[1].vt = VT_BYREF|VT_VARIANT;
				pvars[1].byref = StatusCode; //Pointer to a VT_I4

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0xc, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ClientToHostWindow(SHORT wbUID, LONG * CX, LONG * CY)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				
				pvars[1].vt = VT_BYREF|VT_I4;
				pvars[1].byref = CX;
				
				pvars[0].vt = VT_BYREF|VT_I4;
				pvars[0].byref = CY;

				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0xd, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_FileDownload(SHORT wbUID, VARIANT_BOOL * ActiveDocument, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				
				pvars[1].vt = VT_BYREF|VT_BOOL;
				pvars[1].byref = ActiveDocument;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;
				
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0xe, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_SetSecureLockIcon(SHORT wbUID, LONG SecureLockIcon)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = SecureLockIcon;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0xf, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_WindowClosing(SHORT wbUID, VARIANT_BOOL IsChildWindow, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = IsChildWindow;
				
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x10, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_WindowSetHeight(SHORT wbUID, LONG Height)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Height;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x11, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_WindowSetLeft(SHORT wbUID, LONG Left)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Left;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x12, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_WindowSetResizable(SHORT wbUID, VARIANT_BOOL Resizable)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Resizable;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x13, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_WindowSetTop(SHORT wbUID, LONG Top)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Top;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x14, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_WindowSetWidth(SHORT wbUID, LONG Width)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = Width;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x15, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
//	VOID Fire_ShowMessage(SHORT wbUID, BSTR * sMsg, VARIANT_BOOL * ShowMsg)
//	{
//		//T* pT = static_cast<T*>(this);
//		int nConnectionIndex;
//		CComVariant* pvars = new CComVariant[3];
//		int nConnections = m_vec.GetSize();
//		
//		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
//		{
//			CComPtr<IUnknown> sp;
//			sp.Attach (GetInterfaceAt(nConnectionIndex));
//
//			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
//			if (pDispatch != NULL)
//			{
//				pvars[2] = wbUID;
//
//				pvars[1].vt = VT_BYREF|VT_BSTR;
//				pvars[1].byref = sMsg;
//				
//				pvars[0].vt = VT_BYREF|VT_BOOL;
//				pvars[0].byref = ShowMsg;
//
//				DISPPARAMS disp = { pvars, NULL, 3, 0 };
//				pDispatch->Invoke(0x16, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
//			}
//		}
//		delete[] pvars;
//	
//	}
	VOID Fire_OnContextMenu(SHORT wbUID, LONG ContextMenuType, LONG X, LONG Y, IDispatch * ObjElem, VARIANT_BOOL * ctxDisplay)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = wbUID;
				pvars[4] = ContextMenuType;
				pvars[3] = X;
				pvars[2] = Y;
				pvars[1] = ObjElem;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = ctxDisplay;
				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x1a, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
//	VOID Fire_OnAcceletorKeys(SHORT wbUID, SHORT nKeyCode, SHORT nVirtExtKey, VARIANT_BOOL * Cancel)
//	{
//		//T* pT = static_cast<T*>(this);
//		int nConnectionIndex;
//		CComVariant* pvars = new CComVariant[4];
//		int nConnections = m_vec.GetSize();
//		
//		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
//		{
//			CComPtr<IUnknown> sp;
//			sp.Attach (GetInterfaceAt(nConnectionIndex));
//
//			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
//			if (pDispatch != NULL)
//			{
//				pvars[3] = wbUID;
//				pvars[2] = nKeyCode;
//				pvars[1] = nVirtExtKey;
//				pvars[0].vt = VT_BYREF|VT_BOOL;
//				pvars[0].byref = Cancel;
//				DISPPARAMS disp = { pvars, NULL, 4, 0 };
//				pDispatch->Invoke(0x1b, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
//			}
//		}
//		delete[] pvars;
//	
//	}
	VOID Fire_PrivacyImpactedStateChange(SHORT wbUID, VARIANT_BOOL PrivacyImpacted)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;
				pvars[0] = PrivacyImpacted;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x1c, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_FileDownloadEx(SHORT wbUID, SHORT FileDlUID, BSTR sURL, BSTR sFilename, BSTR sExt, BSTR sExtraHeaders, BSTR sRedirURL, VARIANT_BOOL * SendProgressEvents, VARIANT_BOOL * bStopDownload, BSTR * sPathToSave)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[10];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[9] = wbUID;
				pvars[8] = FileDlUID;
				pvars[7] = sURL;
				pvars[6] = sFilename;
				pvars[5] = sExt;
				pvars[4] = sExtraHeaders;
				pvars[3] = sRedirURL;

				pvars[2].vt = VT_BYREF|VT_BOOL;
				pvars[2].byref = SendProgressEvents;

				pvars[1].vt = VT_BYREF|VT_BOOL;
				pvars[1].byref = bStopDownload;
				
				pvars[0].vt = VT_BYREF|VT_BSTR;
				pvars[0].byref = sPathToSave;

				DISPPARAMS disp = { pvars, NULL, 10, 0 };
				pDispatch->Invoke(0x1e, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnFileDLProgress(SHORT FileDlUID, BSTR sURL, LONG lProgress, LONG lProgressMax, VARIANT_BOOL * CancelDl)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[5];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[4] = FileDlUID;
				pvars[3] = sURL;
				pvars[2] = lProgress;
				pvars[1] = lProgressMax;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = CancelDl;

				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x20, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnFileDLEndDownload(SHORT FileDlUID, BSTR sURL)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = FileDlUID;
				pvars[0] = sURL;
				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x22, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnFileDLDownloadError(SHORT FileDlUID, BSTR sURL, BSTR sErrorMsg)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = FileDlUID;
				pvars[1] = sURL;
				pvars[0] = sErrorMsg;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x23, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnFileDLResponse(SHORT FileDlUID, BSTR sURL, LONG lResponseCode, BSTR sResponseHeaders, VARIANT_BOOL * CancelDl)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[5];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[4] = FileDlUID;
				pvars[3] = sURL;
				pvars[2] = lResponseCode;
				pvars[1] = sResponseHeaders;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = CancelDl;
				
				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x25, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnFileDLCancelDownload(SHORT FileDlUID, BSTR sURL, VARIANT_BOOL CancelledDuringDL)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = FileDlUID;
				pvars[1] = sURL;
				pvars[0] = CancelledDuringDL;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x26, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnFileDLBeginningTransaction(SHORT FileDlUID, BSTR sURL, BSTR sRequestHeaders, BSTR * sAdditionalRequestHeaders, VARIANT_BOOL * bResuming, VARIANT_BOOL * bCancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = FileDlUID;
				pvars[4] = sURL;
				pvars[3] = sRequestHeaders;

				pvars[2].vt = VT_BYREF|VT_BSTR;
 				pvars[2].byref = sAdditionalRequestHeaders;

				pvars[1].vt = VT_BYREF|VT_BOOL;
				pvars[1].byref = bResuming;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = bCancel;

				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x27, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnAuthentication(SHORT wbUID, BSTR * sUsername, BSTR * sPassword, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[4];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[3] = wbUID;

				pvars[2].vt = VT_BYREF|VT_BSTR;
 				pvars[2].byref = sUsername;
				pvars[1].vt = VT_BYREF|VT_BSTR;
 				pvars[1].byref = sPassword;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 4, 0 };
				pDispatch->Invoke(0x29, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnHTTPSecurityProblem(SHORT wbUID, LONG lProblem, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = lProblem;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x2a, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ProtocolHandlerOnBeginTransaction(SHORT wbUID, BSTR sURL, BSTR sRequestHeaders, BSTR * sAdditionalHeaders, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[5];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[4] = wbUID;
				pvars[3] = sURL;
 				pvars[2] = sRequestHeaders;

				pvars[1].vt = VT_BYREF|VT_BSTR;
				pvars[1].byref = sAdditionalHeaders;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x2b, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_ProtocolHandlerOnResponse(SHORT wbUID, BSTR sURL, BSTR sResponseHeaders, BSTR sRedirectedUrl, BSTR sRedirectHeaders, VARIANT_BOOL * Cancel)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = wbUID;
				pvars[4] = sURL;
 				pvars[3] = sResponseHeaders;
 				pvars[2] = sRedirectedUrl;
				pvars[1] = sRedirectHeaders;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Cancel;

				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x2c, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_NewWindow3(SHORT wbUID, IDispatch * * ppDisp, VARIANT_BOOL * Cancel, LONG lFlags, BSTR sURLContext, BSTR sURL)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = wbUID;

				pvars[4].vt = VT_BYREF|VT_DISPATCH;
				pvars[4].byref = ppDisp;
				
				pvars[3].vt = VT_BOOL|VT_BYREF;
				pvars[3].byref = Cancel;

				pvars[2] = lFlags;
				pvars[1] = sURLContext;
				pvars[0] = sURL;
				
				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x2d, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnGetOptionKeyPath(SHORT wbUID, BSTR * sRegistryOptionKeyPath)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;

				pvars[0].vt = VT_BYREF|VT_BSTR;
 				pvars[0].byref = sRegistryOptionKeyPath;

				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x2e, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnGetOverrideKeyPath(SHORT wbUID, BSTR * sRegistryOverrideKeyPath)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = wbUID;

				pvars[0].vt = VT_BYREF|VT_BSTR;
 				pvars[0].byref = sRegistryOverrideKeyPath;

				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x2f, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}

	VOID Fire_OnWBDragEnter(SHORT wbUID, SHORT KeyState, LONG ptX, LONG ptY, LONG * lEffect)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[5];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[4] = wbUID;
				pvars[3] = KeyState;
				pvars[2] = ptX;
				pvars[1] = ptY;
				
				pvars[0].vt = VT_BYREF|VT_I4;
				pvars[0].byref = lEffect;

				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x30, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnWBDragOver(SHORT wbUID, SHORT KeyState, LONG ptX, LONG ptY, LONG * lEffect)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[5];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[4] = wbUID;
				pvars[3] = KeyState;
				pvars[2] = ptX;
				pvars[1] = ptY;
				
				pvars[0].vt = VT_BYREF|VT_I4;
				pvars[0].byref = lEffect;

				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x31, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnWBDrop(SHORT wbUID, SHORT KeyState, LONG ptX, LONG ptY, BSTR lpData, LONG lWBDropFormat, LONG * lEffect)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[7];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[6] = wbUID;
				pvars[5] = KeyState;
				pvars[4] = ptX;
				pvars[3] = ptY;
				pvars[2] = lpData;
				pvars[1] = lWBDropFormat;

				pvars[0].vt = VT_BYREF|VT_I4;
				pvars[0].byref = lEffect;

				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x32, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnWBDragLeave(SHORT wbUID)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[1];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[0] = wbUID;

				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0x33, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	void Fire_OnWMMessage(LONG hWnd, LONG uMsg, LONG wParam, LONG lParam, LONG * lReturn, VARIANT_BOOL * Handled)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = hWnd;
				pvars[4] = uMsg;
				pvars[3] = wParam;
				pvars[2] = lParam;
				pvars[1].vt = VT_BYREF|VT_I4;
				pvars[1].byref = lReturn;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = Handled;
				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				///0x23
				pDispatch->Invoke(0x34, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;	
	}
	VOID Fire_OnPostDataAvailable(SHORT PostUID, BSTR sURL, BSTR pData, VARIANT_BOOL * CancelPost)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[4];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[3] = PostUID;
				pvars[2] = sURL;
				pvars[1]  = pData;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = CancelPost;

				DISPPARAMS disp = { pvars, NULL, 4, 0 };
				pDispatch->Invoke(0x35, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnWBDrop2(SHORT wbUID, SHORT KeyState, LONG ptX, LONG ptY, VARIANT * vData, LONG * lEffect)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = wbUID;
				pvars[4] = KeyState;
				pvars[3] = ptX;
				pvars[2] = ptY;
				pvars[1].vt = VT_BYREF|VT_VARIANT;
				pvars[1].byref = vData;
				
				pvars[0].vt = VT_BYREF|VT_I4;
				pvars[0].byref = lEffect;

				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x36, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnPostOnProgress(SHORT PostUID, BSTR sURL, LONG lProgress, LONG lProgressMax, LONG lStatusCode, BSTR sStatusText, VARIANT_BOOL * CancelPost)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[7];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[6] = PostUID;
				pvars[5] = sURL;
				pvars[4]  = lProgress;
				pvars[3]  = lProgressMax;
				pvars[2]  = lStatusCode;
				pvars[1]  = sStatusText;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = CancelPost;

				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x37, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnPostError(SHORT PostUID, BSTR sURL, BSTR sErrorMsg)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = PostUID;
				pvars[1] = sURL;
				pvars[0]  = sErrorMsg;

				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x38, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnPostEnd(SHORT PostUID, BSTR sURL)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[2];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[1] = PostUID;
				pvars[0] = sURL;

				DISPPARAMS disp = { pvars, NULL, 2, 0 };
				pDispatch->Invoke(0x39, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
	VOID Fire_OnPostResponse(SHORT PostUID, BSTR sURL, LONG lResponseCode, BSTR sResponseHeaders)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[4];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[3] = PostUID;
				pvars[2] = sURL;
				pvars[1]  = lResponseCode;
				pvars[0]  = sResponseHeaders;

				DISPPARAMS disp = { pvars, NULL, 4, 0 };
				pDispatch->Invoke(0x3a, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	
	}
 	VOID Fire_DocumentCompleteWBEx(SHORT wbUID, VARIANT * URL, IDispatch * pDisp, VARIANT_BOOL isTopLevel, BSTR sDocSource)
 	{
 		//T* pT = static_cast<T*>(this);
 		int nConnectionIndex;
 		CComVariant* pvars = new CComVariant[5];
 		int nConnections = m_vec.GetSize();
 		
 		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
 		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

 			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
 			if (pDispatch != NULL)
 			{
 				pvars[4] = wbUID;
				pvars[3].vt = VT_BYREF|VT_VARIANT;
				pvars[3].byref = URL;		//VT_BSTR
 				pvars[2] = pDisp;	//VT_DISPATCH
 				pvars[1] = isTopLevel;
				pvars[0] = sDocSource;
 				DISPPARAMS disp = { pvars, NULL, 5, 0 };
 				pDispatch->Invoke(0x3b, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
 			}
 		}
 		delete[] pvars;
 	}
	VOID Fire_WBProcessUrlAction(SHORT wbUID, BSTR sURL, LONG lUrlAction, LONG PUAF_Flag, LONG * lpUrlPolicy, VARIANT_BOOL * bHandled)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[6];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[5] = wbUID;
				pvars[4] = sURL;
				pvars[3] = lUrlAction;
				pvars[2] = PUAF_Flag;
				pvars[1].vt = VT_BYREF|VT_I4;
				pvars[1].byref = lpUrlPolicy;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = bHandled;

				DISPPARAMS disp = { pvars, NULL, 6, 0 };
				pDispatch->Invoke(0x3c, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_WBEvaluateNewWindow(SHORT wbUID, BSTR sURL, BSTR sName, BSTR sUrlContext, BSTR sFeatures, VARIANT_BOOL bReplace, LONG lFlags, LONG lUserActionTime, LONG * lPopUpAction)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[9];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[8] = wbUID;
				pvars[7] = sURL;
				pvars[6] = sName;
				pvars[5] = sUrlContext;
				pvars[4] = sFeatures;
				pvars[3] = bReplace;
				pvars[2] = lFlags;
				pvars[1] = lUserActionTime;
				pvars[0].vt = VT_BYREF|VT_I4;
				pvars[0].byref = lPopUpAction;

				DISPPARAMS disp = { pvars, NULL, 9, 0 };
				pDispatch->Invoke(0x3d, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_DocHostShowMessage(SHORT wbUID, LONG lHwnd, BSTR strText, BSTR strCaption, LONG lType, BSTR strHelpFile, LONG lHelpContext, LONG * lReturnValue, VARIANT_BOOL * ShowMsgInternaly)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[9];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[8] = wbUID;
				pvars[7] = lHwnd;
				pvars[6] = strText;
				pvars[5] = strCaption;
				pvars[4] = lType;
				pvars[3] = strHelpFile;
				pvars[2] = lHelpContext;
				pvars[1].vt = VT_BYREF|VT_I4;
				pvars[1].byref = lReturnValue;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = ShowMsgInternaly;

				DISPPARAMS disp = { pvars, NULL, 9, 0 };
				pDispatch->Invoke(0x3e, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_FindAnyTextMatchCallback(SHORT wbUID, IDispatch * pHtmlDoc2Disp, IDispatch * pTxtRangeElemDisp, VARIANT_BOOL * bStopSearch)
 	{
 		int nConnectionIndex;
 		CComVariant* pvars = new CComVariant[4];
 		int nConnections = m_vec.GetSize();
 		
 		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
 		{
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

 			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
 			if (pDispatch != NULL)
 			{
 				pvars[3] = wbUID;
 				pvars[2] = pHtmlDoc2Disp;		//VT_DISPATCH
				pvars[1] = pTxtRangeElemDisp;	//VT_DISPATCH
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = bStopSearch;
 				DISPPARAMS disp = { pvars, NULL, 4, 0 };
 				pDispatch->Invoke(0x3f, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
 			}
 		}
 		delete[] pvars;
 	}
	VOID Fire_OnShowScriptError(SHORT wbUID, VARIANT * vErrorLine, VARIANT * vErrorCharacter, VARIANT * vErrorCode, VARIANT * vErrorMsg, VARIANT * vErrorURL, VARIANT_BOOL * bStopRunningScript)
	{
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[7];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[6] = wbUID;
				
				pvars[5].vt = VT_BYREF|VT_VARIANT;
				pvars[5].byref = vErrorLine;
				
				pvars[4].vt = VT_BYREF|VT_VARIANT;
				pvars[4].byref = vErrorCharacter;

				pvars[3].vt = VT_BYREF|VT_VARIANT;
				pvars[3].byref = vErrorCode;

				pvars[2].vt = VT_BYREF|VT_VARIANT;
				pvars[2].byref = vErrorMsg;

				pvars[1].vt = VT_BYREF|VT_VARIANT;
				pvars[1].byref = vErrorURL;

				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = bStopRunningScript;

				DISPPARAMS disp = { pvars, NULL, 7, 0 };
				pDispatch->Invoke(0x40, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}

	/////////////////////////

	VOID Fire_OnHTMLOMWindowServicesMoveTo(SHORT wbUID, LONG x, LONG y)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = x;
				pvars[0] = y;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x41, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnHTMLOMWindowServicesMoveBy(SHORT wbUID, LONG x, LONG y)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = x;
				pvars[0] = y;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x42, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnHTMLOMWindowServicesResizeTo(SHORT wbUID, LONG x, LONG y)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = x;
				pvars[0] = y;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x43, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}
	VOID Fire_OnHTMLOMWindowServicesResizeBy(SHORT wbUID, LONG x, LONG y)
	{
		//T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		CComVariant* pvars = new CComVariant[3];
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			//pT->Lock();
			//CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			//pT->Unlock();
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				pvars[2] = wbUID;
				pvars[1] = x;
				pvars[0] = y;
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x44, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		delete[] pvars;
	}

	VOID Fire_OnWBKeyDown(SHORT wbUID, SHORT nKeyCode, SHORT nVirtExtKey, VARIANT_BOOL * bHandled)
	{
 		int nConnectionIndex;
 		CComVariant* pvars = new CComVariant[4];
 		int nConnections = m_vec.GetSize();
 		
 		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
 		{
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

 			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
 			if (pDispatch != NULL)
 			{
 				pvars[3] = wbUID;
 				pvars[2] = nKeyCode;
				pvars[1] = nVirtExtKey;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = bHandled;

 				DISPPARAMS disp = { pvars, NULL, 4, 0 };
 				pDispatch->Invoke(0x45, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
 			}
 		}
 		delete[] pvars;
	}
	VOID Fire_OnWBKeyUp(SHORT wbUID, SHORT nKeyCode, SHORT nVirtExtKey, VARIANT_BOOL * bHandled)
	{
 		int nConnectionIndex;
 		CComVariant* pvars = new CComVariant[4];
 		int nConnections = m_vec.GetSize();
 		
 		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
 		{
			CComPtr<IUnknown> sp;
			sp.Attach (GetInterfaceAt(nConnectionIndex));

 			IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
 			if (pDispatch != NULL)
 			{
 				pvars[3] = wbUID;
 				pvars[2] = nKeyCode;
				pvars[1] = nVirtExtKey;
				pvars[0].vt = VT_BYREF|VT_BOOL;
				pvars[0].byref = bHandled;

 				DISPPARAMS disp = { pvars, NULL, 4, 0 };
 				pDispatch->Invoke(0x46, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
 			}
 		}
 		delete[] pvars;
	}
};
#endif

