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


class raetsel : public CreatureScript
{

public:
	raetsel() : CreatureScript("raetsel") { }

	bool OnGossipHello(Player *pPlayer, Creature* _creature)
	{
		
		pPlayer->ADD_GOSSIP_ITEM(7, "Das zweite Raetsel", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(7, "Was tust du hier?", GOSSIP_SENDER_MAIN, 1);
        pPlayer->ADD_GOSSIP_ITEM(7, "Wo kann ich die Raetsel abgeben?", GOSSIP_SENDER_MAIN,2);
        pPlayer->ADD_GOSSIP_ITEM(7, "Zeigt mir die Raetsel!", GOSSIP_SENDER_MAIN, 3);
		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * creature, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{

		case 0: {

			pPlayer->GetGUID();
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Ein anderes Wort fuer Dunkel ist gesucht und Soldaten liefen auf gesuchten Routen. Findet ihr dazu 2 Stelzen die Koordinaten veraendern, seid ihr auf dem richtigen Weg.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			return true;
		}break;

		case 1: {

			pPlayer->GetGUID();
			ChatHandler(pPlayer->GetSession()).PSendSysMessage("Hier kann man die lukrativen Raetselquestreihen abschliessen. Werden dir keine Quests angezeigt, hast du nicht die erforderlichen Vorquests abgeschlossen.",
				pPlayer->GetName());
			pPlayer->PlayerTalkClass->SendCloseGossip();
			return true;
		}break;
                
        case 2:
        {
            pPlayer->GetGUID();
            ChatHandler(pPlayer->GetSession()).PSendSysMessage("Gleich nebenmir steht mein Assistent. Bei diesem koennt ihr die Antworten eingeben, so Ihr diese denn wisst. Ihr muesst nicht die Frage angeben, gebt ihm einfach nur die Antwort. Er wird wissen von was Ihr sprecht.", pPlayer->GetName());
            pPlayer->PlayerTalkClass->SendCloseGossip();
            return true;

        }
                
        case 3:
        {
            pPlayer->PlayerTalkClass->ClearMenus();
            pPlayer->ADD_GOSSIP_ITEM(7,"Der Drache", GOSSIP_SENDER_MAIN, 4);
            pPlayer->ADD_GOSSIP_ITEM(7,"Wie alt bin?", GOSSIP_SENDER_MAIN, 5);
            pPlayer->PlayerTalkClass->SendGossipMenu(907, creature->GetGUID());
            return true;

        }
                
            return true;
		}
		return true;
	};

	
};


void AddSC_raetsel()
{
	new raetsel();
}