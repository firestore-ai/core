#pragma once

#include "resource.h" 
#include "../../Common/OfficeFileTemplate.h"

// IOfficeDocFile
[
	object,
	uuid("C694C5ED-201C-46BA-B159-1D7C907FA023"),
	dual,	helpstring("IOfficeDocFile Interface"),
	pointer_default(unique)
]
__interface IOfficeDocFile : IAVSOfficeFileTemplate
{
};

// CASCOfficeDocFile

[
	coclass,
	default(IOfficeDocFile, _IAVSOfficeFileTemplateEvents),
	threading(apartment),
	event_source(com),
	vi_progid("AVSOfficeDocFile.DocFile"),
	progid("AVSOfficeDocFile.DocFile.1"),
	version(1.0),
	uuid("CFABE3C9-A61B-4C20-86F4-A19C8FA1546C"),
	helpstring("OfficeDocFile Class")
]

class ATL_NO_VTABLE CASCOfficeDocFile: public IOfficeDocFile
{
public:

	CASCOfficeDocFile()
	{

	}

	__event __interface _IAVSOfficeFileTemplateEvents;
	__event __interface _IAVSOfficeFileTemplateEvents2;

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	// OfficeFileTemplate Methods
public:

	STDMETHOD(LoadFromFile)(BSTR bsDocFile, BSTR bsDocxFilePath, BSTR bsXMLOptions);
	STDMETHOD(SaveToFile)(BSTR sDstFileName, BSTR sSrcPath, BSTR sXMLOptions);

protected:

	static void OnProgressFunc (LPVOID lpParam, long nID, long nPercent);
	static void OnProgressExFunc (LPVOID lpParam, long nID, long nPercent, short* pStop);
};