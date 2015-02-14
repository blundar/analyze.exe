//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include "CSPIN.h"
#include "FormatedData.h"
//---------------------------------------------------------------------------

class TEpromData;
class TFormatedData;

class TMainFrm : public TForm
{
__published:	// Composants gérés par l'EDI
	TMainMenu *MainMenu1;
	TMenuItem *miFile;
	TMenuItem *miOpen;
	TOpenDialog *OpenDialog;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *edtOffset;
	TCSpinButton *sbOffset;
	TEdit *edtIncrement;
	TCSpinButton *sbIncrement;
	TEdit *edtColumnsNumber;
	TLabel *Label5;
	TCSpinButton *sbColumnsNumber;
	TPanel *Panel2;
	TPaintBox *PaintBox;
	TScrollBar *sbPaintBox;
	TCheckBox *cbMotorolaIntegerFormat;
	TLabel *Label7;
	TEdit *edtPrecision;
	TCSpinButton *sbPrecision;
	TCheckBox *cbSmall;
	TPanel *pnColorMin;
	TPanel *pnColorMax;
	TColorDialog *ColorDialog;
	TScrollBar *sbContrast;
	TLabel *Label4;
	TLabel *lblContrast;
	void __fastcall miOpenClick(TObject *Sender);
	void __fastcall PaintBoxPaint(TObject *Sender);
	void __fastcall edtColumnsNumberExit(TObject *Sender);
	void __fastcall edtOffsetExit(TObject *Sender);
	void __fastcall sbPaintBoxChange(TObject *Sender);
	void __fastcall cbMotorolaIntegerFormatClick(TObject *Sender);
	void __fastcall cbMotorolaIntegerFormatKeyUp(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall edtPrecisionExit(TObject *Sender);
	void __fastcall sbOffsetUpClick(TObject *Sender);
	void __fastcall sbOffsetDownClick(TObject *Sender);
	void __fastcall sbIncrementDownClick(TObject *Sender);
	void __fastcall sbIncrementUpClick(TObject *Sender);
	void __fastcall sbColumnsNumberDownClick(TObject *Sender);
	void __fastcall sbColumnsNumberUpClick(TObject *Sender);
	void __fastcall sbPrecisionUpClick(TObject *Sender);
	void __fastcall sbPrecisionDownClick(TObject *Sender);
	void __fastcall edtIncrementExit(TObject *Sender);
	void __fastcall PaintBoxClick(TObject *Sender);
	void __fastcall cbSmallClick(TObject *Sender);
	void __fastcall cbSmallKeyUp(TObject *Sender, WORD &Key,
		  TShiftState Shift);
	void __fastcall pnColorMinClick(TObject *Sender);
	void __fastcall pnColorMaxClick(TObject *Sender);
	void __fastcall sbContrastChange(TObject *Sender);
private:

	TEpromData* m_pEpromData;
	TFormatedData* m_pFormatedData;

	void __fastcall UpdateTitle(String a_sFileName = "");
	void __fastcall UpdatePaintBox();
	void __fastcall UpdateScrollBar();
	int __fastcall GetLineNumber();
	int __fastcall GetColNumber();
	int __fastcall GetOffset();
	int __fastcall GetPrecision();
	int __fastcall GetIncrement();
	bool __fastcall GetIsMotorolaIntegerFormat();
	int __fastcall GetCellHeight();
	int __fastcall GetCellWidth();
	float __fastcall GetContrast();

	__property int CellHeight  = { read=GetCellHeight };
	__property int CellWidth  = { read=GetCellWidth };

public:

	__fastcall TMainFrm(TComponent* Owner);
	__fastcall ~TMainFrm();

};
//---------------------------------------------------------------------------
extern PACKAGE TMainFrm *MainFrm;
//---------------------------------------------------------------------------
#endif
