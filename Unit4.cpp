 #include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include <System.SysUtils.hpp>
#include <Vcl.Imaging.jpeg.hpp>      
#include <Vcl.Imaging.pngimage.hpp>  

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm4 *Form4;

__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm4::FormCreate(TObject *Sender)
{
    
    DataSource1->DataSet = ADOTable1;
    DBGrid1->DataSource = DataSource1;
    DBNavigator1->DataSource = DataSource1;

   
    Image1->Center = true;
    Image1->Proportional = true;
    Image1->Stretch = true;
    Image1->Visible = false;


    OpenPictureDialog1->Filter =
        L"Images (*.jpg;*.jpeg;*.png;*.bmp)|*.jpg;*.jpeg;*.png;*.bmp|All files (*.*)|*.*";

  
    try
    {
        if (!ADOConnection1->Connected)
            ADOConnection1->Connected = true;

        if (!ADOTable1->Active)
            ADOTable1->Active = true;
    }
    catch (const Exception &e)
    {
        ShowMessage(L"Íå âäàëîñÿ ï³äêëþ÷èòèñÿ äî ÁÄ/òàáëèö³:\n" + e.Message);
    }

    ShowPhotoFromCurrentRecord();
}

void __fastcall TForm4::Button1Click(TObject *Sender)
{
   
    if (OpenPictureDialog1->Execute())
    {
        Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
        Image1->Visible = true;
    }
}

void __fastcall TForm4::Button2Click(TObject *Sender)
{
 
    if (!ADOTable1->Active) return;
    if (Image1->Picture->Graphic == nullptr) return;

    TField *fld = ADOTable1->FieldByName(L"Ôîòîãðàô³ÿ");
    if (fld == nullptr) return;

    std::unique_ptr<TMemoryStream> strm(new TMemoryStream());

    try
    {
       
        if (!(ADOTable1->State == dsEdit || ADOTable1->State == dsInsert))
            ADOTable1->Edit();

        Image1->Picture->Graphic->SaveToStream(strm.get());
        strm->Position = 0;

        
        if (dynamic_cast<TBlobField*>(fld))
            ((TBlobField*)fld)->LoadFromStream(strm.get());
        else if (dynamic_cast<TGraphicField*>(fld))
            ((TGraphicField*)fld)->LoadFromStream(strm.get());
        else
		throw Exception(L"Ïîëå 'Ôîòîãðàô³ÿ' íå º Blob/Graphic ïîëåì.");


        ADOTable1->Post();
        ShowPhotoFromCurrentRecord();
    }
    catch (const Exception &e)
    {
        try { ADOTable1->Cancel(); } catch(...) {}
        ShowMessage(L"Ïîìèëêà çáåðåæåííÿ ôîòî:\n" + e.Message);
    }
}

void __fastcall TForm4::DBGrid1CellClick(TColumn *Column)
{
    ShowPhotoFromCurrentRecord();
}

void __fastcall TForm4::ADOTable1AfterScroll(TDataSet *DataSet)
{
    ShowPhotoFromCurrentRecord();
}

void __fastcall TForm4::ShowPhotoFromCurrentRecord()
{
    if (!ADOTable1->Active)
    {
        Image1->Visible = false;
        return;
    }

    TField *fld = ADOTable1->FieldByName(L"Ôîòîãðàô³ÿ");
    if (fld == nullptr || fld->IsNull)
    {
        Image1->Picture->Assign(nullptr);
        Image1->Visible = false;
        return;
    }

    std::unique_ptr<TMemoryStream> strm(new TMemoryStream());

    try
    {
        if (dynamic_cast<TBlobField*>(fld))
            ((TBlobField*)fld)->SaveToStream(strm.get());
        else if (dynamic_cast<TGraphicField*>(fld))
            ((TGraphicField*)fld)->SaveToStream(strm.get());
        else
           throw Exception(L"Ïîëå 'Ôîòîãðàô³ÿ' íå º Blob/Graphic ïîëåì.");


        if (strm->Size < 4)
        {
            Image1->Visible = false;
            return;
        }

        strm->Position = 0;

   
        Image1->Picture->LoadFromStream(strm.get());
        Image1->Visible = true;
    }
    catch (...)
    {
        Image1->Picture->Assign(nullptr);
        Image1->Visible = false;
    }
}


