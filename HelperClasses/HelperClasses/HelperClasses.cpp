#include <wx/string.h>
#include <wx/utils.h>
#include <wx/private/wxprintf.h>
#include <wx/datetime.h>
#include <wx/file.h>
#include <wx/textfile.h>
#include <wx/dir.h>
#include <wx/filefn.h>

void TestString()
{
	wxString str1 = wxT("This example ");
	wxString str2 = wxT("by KiemVM");
	wxString str3;
	str3.Printf(wxT("Format string : %d\n"), str1.Len());
	wxPrintf(str1 + str2.MakeUpper() + wxT("\n") + str3.MakeLower());
}

void TestUltilFunction()
{
	//wxShell(wxT("dir"));
	wxString strHomeDir = wxGetHomeDir();
	wxString strOsDescription = wxGetOsDescription();
	wxString strUserName = wxGetUserName();
	wxString strFullHostName = wxGetFullHostName();
	wxPrintf(strHomeDir + wxT("\n") + strOsDescription + wxT("\n") + strUserName + wxT("\n") + strFullHostName);
}

void TestDateTime()
{
	wxDateTime now = wxDateTime::Now();
	wxString date1 = now.Format();
	wxString date2 = now.Format(wxT("%X"));
	wxString date3 = now.Format(wxT("%x"));
	wxPuts(date1);
	wxPuts(date2);
	wxPuts(date3);
	wxPrintf(wxT("   Tokyo: %s\n"), now.Format(wxT("%a %T"),
		wxDateTime::GMT9).c_str());
}

void TestFile()
{
	wxFile file;
	file.Create(wxT("Example.txt"), true);
	if (file.IsOpened())
	{
		wxPuts(wxT("file is opened"));
	}

	file.Write(wxT("this is example by KiemVM"));
	file.Close();
	
	// read file
	wxTextFile fileText;
	fileText.Open(wxT("Example.txt"));
	wxPrintf(wxT("Number of lines: %d\n"), fileText.GetLineCount());
	wxPrintf(wxT("First line: %s\n"), fileText.GetFirstLine().c_str());
	wxPrintf(wxT("Last line: %s\n"), fileText.GetLastLine().c_str());
}

void TestDir()
{
	wxDir dir(wxGetCwd());
	wxString file;
	bool cont = dir.GetFirst(&file, wxEmptyString, wxDIR_FILES | wxDIR_DIRS);
	while (cont)
	{
		wxPuts(file);
		cont = dir.GetNext(&file);
	}
}

int main(int argc, char **argv)
{
	wxPuts(wxT("-------- String ---------"));
	TestString();
	
	wxPuts(wxT("----------- Ultil Functions ------------------"));
	TestUltilFunction();

	wxPuts(wxT("---------------- Date time ---------------------"));
	TestDateTime();

	wxPuts(wxT("----------------- Files ------------------"));
	TestFile();

	wxPuts(wxT("----------------- Dir --------------"));
	TestDir();
}