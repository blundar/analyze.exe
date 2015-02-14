//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "EpromData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

__fastcall TEpromData::TEpromData()
{
	m_pDataStream = new TMemoryStream;
}
//---------------------------------------------------------------------------

__fastcall TEpromData::~TEpromData()
{
	delete m_pDataStream;
}
//---------------------------------------------------------------------------

bool __fastcall TEpromData::OpenFile(String a_sFileName)
{
	bool bResult = true;
	m_pDataStream->Clear();

	if (!::FileExists(a_sFileName))
		bResult = false;
	else
	{
		try
		{
			TFileStream* pFileStream = NULL;
			try
			{
				pFileStream = new TFileStream( a_sFileName, fmOpenRead | fmShareCompat	);
				// Se positionne au début du flux
				pFileStream->Seek( 0, soFromBeginning );
				// Copie dans le tampon mémoire
				m_pDataStream->CopyFrom( pFileStream, pFileStream->Size );
			}
			__finally
			{
				delete pFileStream;
			}
		}
		catch (Exception &E)
		{
			bResult = false;
		}
	}

	return bResult;
}
//---------------------------------------------------------------------------

bool __fastcall TEpromData::SaveFile(String a_sFileName)
{
	bool bResult = true;

	try
	{
		// Suppression du fichier destination s'il existe déjà
		if (::FileExists(a_sFileName)) ::DeleteFile( a_sFileName.c_str() );

		TFileStream* pFileStream = NULL;
		try
		{
			pFileStream = new TFileStream( a_sFileName, fmCreate | fmShareExclusive	);
			// Sauvegarde du contenu du tampon mémoire dans le fichier
			m_pDataStream->Position = 0;
			pFileStream->CopyFrom( m_pDataStream, m_pDataStream->Size );
		}
		__finally
		{
			// Fermeture du fichier
			delete pFileStream;
		}
	}
	catch (Exception &E)
	{
		bResult = false;
	}

	return bResult;
}
//---------------------------------------------------------------------------

void __fastcall TEpromData::SetData(int a_Position, unsigned char a_Value)
{
	if ((a_Position>=0) && (a_Position<m_pDataStream->Size))
	{
		m_pDataStream->Position = a_Position;
		m_pDataStream->Write(&a_Value, 1);
	}
	else throw EOverflow( "Ca déborde!!!" );
}
//---------------------------------------------------------------------------

unsigned char __fastcall TEpromData::GetData(int a_Position)
{
	unsigned char Result;

	if ((a_Position>=0) && (a_Position<m_pDataStream->Size))
	{
		m_pDataStream->Position = a_Position;
		m_pDataStream->Read(&Result, 1);
	}
	else throw EOverflow( "Erreur: Dépassement de fin de fichier.\n\n[TEpromData::GetData()]\n" + String(__FILE__) );

	return Result;
}
//---------------------------------------------------------------------------

int __fastcall TEpromData::GetSize()
{
	return m_pDataStream->Size;
}
//---------------------------------------------------------------------------

