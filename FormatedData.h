//---------------------------------------------------------------------------

#ifndef FormatedDataH
#define FormatedDataH
//---------------------------------------------------------------------------

class TEpromData;
class TFormatedData : public TObject
{
	typedef TObject Inherited;

private:

	TEpromData* m_pEpromData;
	int m_iOffset;
	TColor m_ColorMin;
	TColor m_ColorMax;
	bool m_bMotorolaIntegerFormat;
	bool m_bHexadecimal;
	int m_iPrecision;
	float m_fContrast;

	TColor __fastcall MixColors(TColor a_Color1, TColor a_Color2, double a_RatioC1, double a_RatioC2);
	String __fastcall GetAsText();
	TColor __fastcall GetBgColor();
	TColor __fastcall GetTextColor();
	double __fastcall GetAsdouble();
	double __fastcall GetMaxValue();
	bool __fastcall GetIsInteger();

	__property double Asdouble   = { read=GetAsdouble };
	__property double MaxValue  = { read=GetMaxValue };
	__property bool IsInteger  = { read=GetIsInteger };

public:

	__fastcall TFormatedData(TEpromData* a_pEpromData);

	__property int Offset = { read=m_iOffset, write=m_iOffset };
	__property TColor ColorMin  = { read=m_ColorMin, write=m_ColorMin };
	__property TColor ColorMax  = { read=m_ColorMax, write=m_ColorMax };
	__property bool MotorolaIntegerFormat  = { read=m_bMotorolaIntegerFormat, write=m_bMotorolaIntegerFormat };
	__property bool Hexadecimal  = { read=m_bHexadecimal, write=m_bHexadecimal };
	__property int Precision  = { read=m_iPrecision, write=m_iPrecision };

	__property String AsText  = { read=GetAsText };
	__property TColor BgColor  = { read=GetBgColor };
	__property TColor TextColor  = { read=GetTextColor };
	__property float Contrast  = { read=m_fContrast, write=m_fContrast };

};

//---------------------------------------------------------------------------
#endif
