//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Analyze.res");
USEFORM("Main.cpp", MainFrm);
USEUNIT("EpromData.cpp");
USEUNIT("FormatedData.cpp");
USEUNIT("Tools.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "Analyzer";
		Application->CreateForm(__classid(TMainFrm), &MainFrm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	return 0;
}
//---------------------------------------------------------------------------
