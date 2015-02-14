//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "Main.h"
#include <Math.h>
#include "Tools.h"
#include "EpromData.h"

//---------------------------------------------------------------------------

#define CELL_HEIGHT			19
#define CHAR_WIDTH			6
#define CELL_SMALL_HEIGHT	10
#define CELL_SMALL_WIDTH	10

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TMainFrm *MainFrm;
//---------------------------------------------------------------------------

__fastcall TMainFrm::TMainFrm(TComponent* Owner)
	: TForm(Owner)
{
	UpdateTitle();

	m_pEpromData = new TEpromData;
	m_pFormatedData = new TFormatedData(m_pEpromData);

	m_pFormatedData->Offset = GetOffset();
	m_pFormatedData->ColorMin = pnColorMin->Color;
	m_pFormatedData->ColorMax = pnColorMax->Color;
	m_pFormatedData->MotorolaIntegerFormat = GetIsMotorolaIntegerFormat();
	m_pFormatedData->Contrast = GetContrast();

	UpdateScrollBar();
}
//---------------------------------------------------------------------------

__fastcall TMainFrm::~TMainFrm()
{
	delete m_pFormatedData;
	delete m_pEpromData;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::UpdateTitle(String a_sFileName /*=""*/)
{
	if (a_sFileName.IsEmpty()) a_sFileName = "Aucun fichier ouvert";
	Caption = Application->Title + " - " + a_sFileName;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::miOpenClick(TObject *Sender)
{
	if (OpenDialog->Execute())
	{
		m_pEpromData->OpenFile(OpenDialog->FileName);
		UpdateTitle(OpenDialog->FileName);
		sbPaintBox->Max = m_pEpromData->Size;
		UpdatePaintBox();
	}
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
// Gestion de la zone de dessin
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

int __fastcall TMainFrm::GetCellHeight()
{
	return (cbSmall->Checked) ? CELL_SMALL_HEIGHT : CELL_HEIGHT;
}
//---------------------------------------------------------------------------

int __fastcall TMainFrm::GetCellWidth()
{
	int iResult = CELL_SMALL_WIDTH;
	if (!cbSmall->Checked)
	{
		double dMax = pow(2, GetPrecision() * 8);
		String sTemp = String(dMax);
		iResult = sTemp.Length() * CHAR_WIDTH + 4;
	}
	return iResult;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::UpdatePaintBox()
{
	PaintBox->Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::PaintBoxPaint(TObject *Sender)
{
	// Positionne offset premiére cellule
	m_pFormatedData->Offset = GetOffset();
	m_pFormatedData->MotorolaIntegerFormat = cbMotorolaIntegerFormat->Checked;
	m_pFormatedData->Precision = GetPrecision();

	int iColNumber = GetColNumber();
	int iLineNumber = GetLineNumber();

	// Parcours des cellules et dessin
	for (int iLine=0; iLine < iLineNumber; iLine++)
	{
		for (int iCol=0; iCol < iColNumber; iCol++)
		{
			// Coordonnées de la cellule
			TRect CellRect;
			CellRect.Top = iLine * CellHeight;
			CellRect.Left = iCol * CellWidth;
			CellRect.Bottom = CellRect.Top + CellHeight;
			CellRect.Right = CellRect.Left + CellWidth;

			// Dessin de la cellule
			TColor clr = m_pFormatedData->BgColor;
			PaintBox->Canvas->Pen->Color = clr;
			PaintBox->Canvas->Brush->Color = clr;
			PaintBox->Canvas->Rectangle(CellRect);

			if (!cbSmall->Checked)
			{
				// Dessin du texte
				PaintBox->Canvas->Font->Color = m_pFormatedData->TextColor;
				PaintBox->Canvas->TextOut(CellRect.Left+2, CellRect.Top+2, m_pFormatedData->AsText);
			}

			// Passe aux données de la cellule suivante
			m_pFormatedData->Offset = m_pFormatedData->Offset + GetPrecision();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::PaintBoxClick(TObject *Sender)
{
	sbPaintBox->SetFocus();
}
//---------------------------------------------------------------------------

int __fastcall TMainFrm::GetLineNumber()
{
	return PaintBox->Height / CellHeight;
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
// Gestion des zones de saisie
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

int __fastcall TMainFrm::GetOffset()
{
	int iResult = String("0x" + edtOffset->Text).ToIntDef(-1);
	if (iResult < 0) EXCEPT("Saisie non Valide");
	return iResult;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::edtOffsetExit(TObject *Sender)
{
	int iValue = String("0x" + edtOffset->Text).ToIntDef(-1);

	if (iValue < 0)
	{
		Application->MessageBox("Saisie invalide.\nSaisissez une adresse hexadécimale supérieure à 0", "Avertissement", MB_OK | MB_ICONEXCLAMATION );
		edtOffset->SetFocus();
	}
	else
	{
		// Synchronise la scroll-bar
		UpdateScrollBar();
		UpdatePaintBox();
	}
}
//---------------------------------------------------------------------------

int __fastcall TMainFrm::GetPrecision()
{
	int iResult = edtPrecision->Text.ToIntDef(-1);
	if (iResult < 1) EXCEPT( "Erreur de saisie" );
	return iResult;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::edtPrecisionExit(TObject *Sender)
{
	int iValue = edtPrecision->Text.ToIntDef(-1);

	if (iValue < 0)
	{
		Application->MessageBox("Saisie invalide.\nSaisissez une adresse hexadécimale supérieure à 0", "Avertissement", MB_OK | MB_ICONEXCLAMATION );
		edtPrecision->SetFocus();
	}
	else
		UpdatePaintBox();
}
//---------------------------------------------------------------------------

int __fastcall TMainFrm::GetIncrement()
{
	int iIncrement = edtIncrement->Text.ToIntDef(-1);
	if (iIncrement < 1) EXCEPT( "Saisie invalide" );
	return iIncrement;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::edtIncrementExit(TObject *Sender)
{
	int iIncrement = edtIncrement->Text.ToIntDef(-1);
	if (iIncrement < 1)
	{
		Application->MessageBox("Saisie invalide.\nSaisissez une valeur supérieure à 0", "Avertissement", MB_OK | MB_ICONEXCLAMATION );
		edtIncrement->SetFocus();
	}
}
//---------------------------------------------------------------------------

int __fastcall TMainFrm::GetColNumber()
{
	int iResult = edtColumnsNumber->Text.ToIntDef(-1);
	if ((iResult < 1) || (iResult > 64)) EXCEPT("Saisie non Valide");
	return iResult;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::edtColumnsNumberExit(TObject *Sender)
{
	int iValue = edtColumnsNumber->Text.ToIntDef(-1);

	if ((iValue < 1) || (iValue > 64))
	{
		Application->MessageBox("Saisie invalide (0<Valeur<=64)", "Avertissement", MB_OK | MB_ICONEXCLAMATION );
		edtColumnsNumber->SetFocus();
	}
	else
	{
		UpdateScrollBar();
		UpdatePaintBox();
	}
}
//---------------------------------------------------------------------------

bool __fastcall TMainFrm::GetIsMotorolaIntegerFormat()
{
	return cbMotorolaIntegerFormat->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::cbMotorolaIntegerFormatClick(TObject *Sender)
{
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::cbMotorolaIntegerFormatKeyUp(TObject *Sender,
	  WORD &Key, TShiftState Shift)
{
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbOffsetUpClick(TObject *Sender)
{
	int iOffset = GetOffset();
	iOffset += GetIncrement() * GetPrecision();
	edtOffset->Text = AnsiString::IntToHex(iOffset, 8);
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbOffsetDownClick(TObject *Sender)
{
	int iOffset = GetOffset();
	iOffset -= GetIncrement() * GetPrecision();
	iOffset = max(iOffset, 0);
	edtOffset->Text = AnsiString::IntToHex(iOffset, 8);
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbIncrementDownClick(TObject *Sender)
{
	edtIncrement->Text = String(max(GetIncrement()-1, 1));
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbIncrementUpClick(TObject *Sender)
{
	edtIncrement->Text = String(GetIncrement()+1);
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbColumnsNumberDownClick(TObject *Sender)
{
	edtColumnsNumber->Text = String(max(GetColNumber()-1, 1));
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbColumnsNumberUpClick(TObject *Sender)
{
	edtColumnsNumber->Text = String(GetColNumber()+1);
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbPrecisionUpClick(TObject *Sender)
{
	edtPrecision->Text = String(min(GetPrecision()+1, 4));
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbPrecisionDownClick(TObject *Sender)
{
	edtPrecision->Text = String(max(GetPrecision()-1, 1));
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::cbSmallClick(TObject *Sender)
{
	UpdateScrollBar();
	UpdatePaintBox();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::cbSmallKeyUp(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	UpdateScrollBar();
	UpdatePaintBox();
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
// Gestion de la scroll-bar
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

void __fastcall TMainFrm::UpdateScrollBar()
{
	sbPaintBox->Position = GetOffset();
	sbPaintBox->SmallChange = GetColNumber() * GetPrecision();
	sbPaintBox->LargeChange = GetColNumber() * GetPrecision() * GetLineNumber();
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbPaintBoxChange(TObject *Sender)
{
	edtOffset->Text = AnsiString::IntToHex(sbPaintBox->Position, 8);
	UpdatePaintBox();
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
// Gestion des couleurs
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

void __fastcall TMainFrm::pnColorMinClick(TObject *Sender)
{
	ColorDialog->Color = pnColorMin->Color;
	if (ColorDialog->Execute())
	{
		pnColorMin->Color = ColorDialog->Color;
		m_pFormatedData->ColorMin = pnColorMin->Color;
		UpdatePaintBox();
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::pnColorMaxClick(TObject *Sender)
{
	ColorDialog->Color = pnColorMax->Color;
	if (ColorDialog->Execute())
	{
		pnColorMax->Color = ColorDialog->Color;
		m_pFormatedData->ColorMax = pnColorMax->Color;
		UpdatePaintBox();
	}
}
//---------------------------------------------------------------------------

float __fastcall TMainFrm::GetContrast()
{
	return float(sbContrast->Position) / 100;
}
//---------------------------------------------------------------------------

void __fastcall TMainFrm::sbContrastChange(TObject *Sender)
{
	lblContrast->Caption = String(sbContrast->Position);
	m_pFormatedData->Contrast = GetContrast();
	UpdatePaintBox();
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

