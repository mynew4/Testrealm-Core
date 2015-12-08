#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include "Bag.h"
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


class sb_uebung : public CreatureScript
{

public:
	sb_uebung() : CreatureScript("sb_uebung") { }

	bool OnGossipHello(Player* pPlayer, Creature* _creature)
	{
		pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 1", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 2", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(7, "Funktion 3", GOSSIP_SENDER_MAIN, 2);
		
		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;

}
	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{
		case 0:
		{}
		case 1:
		{}
		case 2:
		{}
		return true;
		}
	}
void AddSC_sb_uebung()
{
	new sb_uebung();
}