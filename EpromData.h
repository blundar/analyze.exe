//---------------------------------------------------------------------------
#ifndef EpromDataH
#define EpromDataH
//---------------------------------------------------------------------------

class TEpromData : public TObject
{
	typedef TObject Inherited;

private:

	TMemoryStream* m_pDataStream;

	void __fastcall SetData(int a_Position, unsigned char a_Value);
	unsigned char __fastcall GetData(int a_Position);
	int __fastcall GetSize();

public:

	virtual __fastcall TEpromData	();
	virtual __fastcall ~TEpromData	();

	bool __fastcall OpenFile	(String a_sFileName);
	bool __fastcall SaveFile	(String a_sFileName);

	__property TMemoryStream* RawData = { read=m_pDataStream };
	__property unsigned char Data[int] = { read=GetData, write=SetData };
	__property int Size = { read=GetSize };

};
//---------------------------------------------------------------------------
#endif
