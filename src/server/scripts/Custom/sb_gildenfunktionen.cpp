#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
#include "Mail.h"
#include "Common.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"
#include "Define.h"
#include "Field.h"
#include "GameEventMgr.h"
#include "Item.h"
#include "ItemPrototype.h"
#include "Language.h"
#include "Log.h"
#include "ObjectGuid.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "QueryResult.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "Transaction.h"
#include "WorldSession.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Guild.h"
#include "Arena.h"
#include "ArenaTeam.h"
#include "ArenaScore.h"
#include "Guild.h"
#include "GuildMgr.h"




class gildengold : public PlayerScript
{
public:
    gildengold() : PlayerScript("gildengold") {}
    
    virtual void OnMoneyChanged(Player* player, int32& /*amount*/) {
    
        Guild* guild = player->GetGuild();
        guild->MassInviteToEvent(player->GetSession(), 80, 80, 0);
        
        
        
    }
};




/*
class ruhestein : public PlayerScript
{

public:
	ruhestein() : PlayerScript("ruhestein") { }

	// zZauber ist Variable f�r Ruhestein-zauber
	// cCooldown ist Variable f�r Cooldown vom Ruhestein

	void OnSpellCast(Player* pPlayer, Spell* spell, bool skipCheck)
	{
	SpellInfo const* zZauber;

		if (zZauber->Id == 8690)
		{
			uint32 cCooldown = pPlayer->GetRuneCooldown(6948) * 0.5;
			pPlayer->SetRuneCooldown(6948, cCooldown, true);

		}
	}

};

*/




void AddSC_sb_gildenfunktionen()
{
	new gildengold();

}

