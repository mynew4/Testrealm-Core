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


class weihnachtseventwillkommen : public CreatureScript
{

public:
	weihnachtseventwillkommen() : CreatureScript("weihnachtseventwillkommen") { }

	bool OnGossipHello(Player *pPlayer, Creature* _creature)
	{
      
        bool status = pPlayer->GetQuestRewardStatus(900001);
        if (status){
            pPlayer->ADD_GOSSIP_ITEM(7, "Teleportiert mich nach oben.", GOSSIP_SENDER_MAIN, 0);
        }

		pPlayer->ADD_GOSSIP_ITEM(7, "Was bin ich?", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(7, "Gibt es eine Moeglichkeit einen Port zu nehmen?", GOSSIP_SENDER_MAIN, 2);
        
		pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * /*pCreature */, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{

			case 0: {
                //Port to upper position
                pPlayer->TeleportTo(1,16220.94,16350.46,210.77,1.48);
				pPlayer->PlayerTalkClass->SendCloseGossip();
				pPlayer->GetGUID();
				return true;
			}break;
             

			case 1:
			{
				pPlayer->GetGUID();
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Ich bin ein Weihnachtswichtel. Ich bin verantwortlich damit nur Gnome hier durchkommen.",
					pPlayer->GetName());
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}break;


			case 2:
			{
				pPlayer->GetGUID();
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("Wenn ihr die Quest abgeschlossen habt, koennt ihr Euch immer wieder nach oben porten.",
					pPlayer->GetName());
				pPlayer->PlayerTalkClass->SendCloseGossip();
			}break;

			return true;
		}
		return true;
	};
};


class weihnachtseventplattform : public CreatureScript
{

public:
	weihnachtseventplattform() : CreatureScript("weihnachtseventplattform") { }


	bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*opt*/)
	{
		
		if (quest->GetQuestId() == 900001){   //Erste Quest
			player->AddAura(155,player);  //Weihnachtswichtel		
		}
		return true;
	}

};

void AddSC_weihnachtsevent()
{
	new weihnachtseventwillkommen();
	new weihnachtseventplattform();
}