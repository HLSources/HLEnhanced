#include "extdll.h"
#include "util.h"

#include "Angelscript/CHLASManager.h"

#include "Angelscript/ScriptAPI/ASPluginInterface.h"

#include "Angelscript/ScriptAPI/Entities/ASEntityFuncs.h"

#include "Angelscript/ScriptAPI/ASTriggerScript.h"

#include "Angelscript/ScriptAPI/ASGameRules.h"

#include "Angelscript/ScriptAPI/Extensions/CASGameRules.h"

#if USE_AS_SQL
#include "Angelscript/ScriptAPI/SQL/ASHLSQL.h"
#endif

#include "CHLASServerInitializer.h"

bool CHLASServerInitializer::RegisterCoreAPI( CASManager& manager )
{
	CHLASBaseInitializer::RegisterCoreAPI( manager );

	auto& engine = *manager.GetEngine();

	RegisterScriptPluginInterface( engine );

	//CBaseEntity is registered by CHLASBaseInitializer
	RegisterScriptEntityFuncs( engine );

	RegisterScriptTriggerScript( engine );

	engine.RegisterInterface( "IGameRules" );

	RegisterScriptCGameRules( engine );
	RegisterScriptGameRules( engine );

#if USE_AS_SQL
	RegisterScriptHLSQL( engine );
#endif

	return true;
}