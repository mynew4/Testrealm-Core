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



	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		pPlayer->ADD_GOSSIP_ITEM(7, "1 level aufsteigen. Kosten: 10 Astrale Kredite", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(7, "10 level aufsteigen.  Kosten: 90 Astrale Kredite.", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(7, "Auf Level 80 setzen.  Kosten: 800 Astrale Kredite.", GOSSIP_SENDER_MAIN, 2);

		pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
		return true;

	}

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		switch (uiAction)
		{
		case 0:
		{
			uint16 levela = pPlayer->getLevel();

			if (levela < 80)
			{
				uint16 levelb = levela + 1;
				uint16 kosten = 10;

				if (pPlayer->HasItemCount(38186, kosten))
				{
					pPlayer->SetLevel(levelb);
					pPlayer->DestroyItemCount(38186, kosten, true);
					pPlayer->GetSession()->SendNotification("Dir wurden 10 Astralekredite abgezogen und du bist 1 Level höher");
					return true;
				}

				else
				{
					pPlayer->GetSession()->SendNotification("Du hast leider keine 10 Astralenkredite");
					return false;
				}
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Du bist schon Level 80!");
				return true;
			}
		}break;

		
		case 1:
		{
			uint16 levela = pPlayer->getLevel();

			if (levela <= 70)
			{
				uint16 levelb = levela + 10;
				uint16 kosten = 90;

				if (pPlayer->HasItemCount(38186, kosten, true))
				{
					pPlayer->SetLevel(levelb);
					pPlayer->DestroyItemCount(38186, kosten);
					pPlayer->GetSession()->SendNotification("Dir wurden 90 Astralekredite abgezogen und du bist 1 Level höher");
					return true;
				}

				else
				{
					pPlayer->GetSession()->SendNotification("Du hast leider keine 90 Astralenkredit");
					return false;
				}
			}
			else
			{
				pPlayer->GetSession()->SendNotification("Du bist schon über Level 70!");
				return true;
			}
		}break;

	
		case 2:
		{
			uint16 kosten = 800;

				if (pPlayer->HasItemCount(38186, kosten))
				{
					pPlayer->SetLevel(80);
					pPlayer->DestroyItemCount(38186, kosten, true);
					pPlayer->GetSession()->SendNotification("Dir wurden 800 Astralekredite abgezogen und du bist 1 Level höher");
					return true;
				}

				else
				{
					pPlayer->GetSession()->SendNotification("Du hast leider keine 800 Astralenkredit");
					return false;
				}
			
			
		}break;


		}
	}

};

void AddSC_sb_uebung()
{
	new sb_uebung();
}








