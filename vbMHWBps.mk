
vbMHWBps.dll: dlldata.obj vbMHWB_p.obj vbMHWB_i.obj
	link /dll /out:vbMHWBps.dll /def:vbMHWBps.def /entry:DllMain dlldata.obj vbMHWB_p.obj vbMHWB_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del vbMHWBps.dll
	@del vbMHWBps.lib
	@del vbMHWBps.exp
	@del dlldata.obj
	@del vbMHWB_p.obj
	@del vbMHWB_i.obj
