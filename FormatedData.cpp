//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------

#include "FormatedData.h"
#include <Math.h>
#include "Tools.h"
#include "EpromData.h"

#define EMPTY_CELL "---"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall TFormatedData::TFormatedData(TEpromData* a_pEpromData)
{
	m_pEpromData = a_pEpromData;

	m_iOffset = 0;
	m_ColorMin = clRed;
	m_ColorMax = clYellow;
	m_bMotorolaIntegerFormat = false;
	m_bHexadecimal = true;
	m_fContrast = 0.5;
}
//---------------------------------------------------------------------------

TColor __fastcall TFormatedData::MixColors(TColor a_Color1, TColor a_Color2,
	double a_RatioC1, double a_RatioC2)
{
	int clr1, clr2;

	if (a_RatioC1 + a_RatioC2 == 0) return (TColor)0x0;     // Noir

	// Convertion en RGB
	clr1 = ColorToRGB(a_Color1);
	clr2 = ColorToRGB(a_Color2);

	// Melange des composantes une à une.
	int red   = (a_RatioC1 * double(GetRValue(clr1)) + a_RatioC2 * double(GetRValue(clr2))) / (a_RatioC1 + a_RatioC2);
	int green = (a_RatioC1 * double(GetGValue(clr1)) + a_RatioC2 * double(GetGValue(clr2))) / (a_RatioC1 + a_RatioC2);
	int blue  = (a_RatioC1 * double(GetBValue(clr1)) + a_RatioC2 * double(GetBValue(clr2))) / (a_RatioC1 + a_RatioC2);

	return (TColor)RGB(red,green,blue);
}
//---------------------------------------------------------------------------

String __fastcall TFormatedData::GetAsText()
{
	String sResult = EMPTY_CELL;
	if (m_iOffset < m_pEpromData->Size - m_iPrecision)
	{
		if (IsInteger)
			sResult = String(Asdouble);
		else
			sResult = String(Asdouble);
	}
	return sResult;
}
//---------------------------------------------------------------------------

TColor __fastcall TFormatedData::GetBgColor()
{
	TColor clrResult = clWhite;

	if (m_iOffset < m_pEpromData->Size - m_iPrecision)
	{
		double fMaxValue = MaxValue;
		double fMinValue = 0;
		double fValue = Asdouble;

		if (Contrast > 0.5)
			fMaxValue = fMaxValue * (1-Contrast)*2;
		else
			fMinValue = fMaxValue - (fMaxValue * Contrast*2);

		fValue = min(fMaxValue, fValue);
		fValue = max(fMinValue, fValue);

		clrResult = MixColors(	ColorMin,
								ColorMax,
								(fMaxValue - fMinValue) - fValue,
								fValue - fMinValue);
	}
	return clrResult;
}
//---------------------------------------------------------------------------

TColor __fastcall TFormatedData::GetTextColor()
{
	//TODO
	return clBlack;
}
//---------------------------------------------------------------------------

double __fastcall TFormatedData::GetAsdouble()
{
	//TODO
	if (m_iOffset >= m_pEpromData->Size - m_iPrecision) EXCEPT( "Index hors limite" );

	String sData;
	for (int i=0; i < m_iPrecision; i++)
	{
		String sTempData = AnsiString::IntToHex(int(m_pEpromData->Data[m_iOffset+i]), 2);
		// Les processeurs Intel et Motorola ne stockent pas les entiers de
		// la même maniére
		if (m_bMotorolaIntegerFormat)
			sData = sData + sTempData;
		else
			sData = sTempData + sData;
	}

	double dResult;
	if (sData.Length() < 8)
	{
		sData = "0x" + sData;
		dResult = sData.ToInt();
	}
	else
	{
		// Effectue la conversion en 2 étapes
		String sTemp = "0x" + sData.SubString(4, 4);
		dResult = sTemp.ToInt();
		sTemp = "0x" + sData.SubString(1, 4);
		dResult = dResult + (sTemp.ToInt() * pow(2, 16));
	}

	return dResult;
}
//---------------------------------------------------------------------------

double __fastcall TFormatedData::GetMaxValue()
{
	//TODO
	return pow(2, 8*m_iPrecision);
}
//---------------------------------------------------------------------------

bool __fastcall TFormatedData::GetIsInteger()
{
	//TODO
	return true;
}
//---------------------------------------------------------------------------
