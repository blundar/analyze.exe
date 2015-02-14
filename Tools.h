//---------------------------------------------------------------------------
#ifndef ToolsH
#define ToolsH
//---------------------------------------------------------------------------

// Gestion d'erreur
#define EXCEPT(text) throw Exception(String(text) + "\n\n  Fichier : " + String(__FILE__) + "\n  Ligne  : " + String(__LINE__)) 


//---------------------------------------------------------------------------
#endif
