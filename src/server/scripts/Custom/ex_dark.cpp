#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"




class dark : public CreatureScript
{
public: dark() : CreatureScript("dark"){ }

		bool OnGossipHello(Player *pPlayer, Creature* _creature)
		{
            Group* group = pPlayer->GetGroup();
            if(group){
                pPlayer->ADD_GOSSIP_ITEM(7, "Unterstuetzt mich, Prinz! [4 Abzeichen]", GOSSIP_SENDER_MAIN, 0);
                pPlayer->ADD_GOSSIP_ITEM(7, "Zeigt mir wo der Prinz haust.", GOSSIP_SENDER_MAIN, 1);
            }
			
			pPlayer->ADD_GOSSIP_ITEM(7, "Ich brauche eure Hilfe doch nicht!",GOSSIP_SENDER_MAIN, 3);
			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
			case 0:
			{	
				if (pPlayer->HasItemCount(700518, 4)){
					pPlayer->DestroyItemCount(700518, 4, true);
					pPlayer->AddAura(48161, pPlayer);              // Power Word: Fortitude        
					pPlayer->AddAura(48073, pPlayer);              // Divine Spirit
					pPlayer->AddAura(20217, pPlayer);              // Blessing of Kings
					pPlayer->AddAura(48469, pPlayer);              // Mark of the wild
					pPlayer->AddAura(16609, pPlayer);              // Spirit of Zandalar
					pPlayer->AddAura(15366, pPlayer);              // Songflower Serenade
					pPlayer->AddAura(22888, pPlayer);              // Rallying Cry of the Dragonslayer
					pPlayer->AddAura(57399, pPlayer);              // Well Fed
					pPlayer->AddAura(17013, pPlayer);              // Agamaggan's Agility
					pPlayer->AddAura(16612, pPlayer);              // Agamaggan's Strength
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}

				else {
					pPlayer->GetSession()->SendAreaTriggerMessage("Leider hast du nicht genug Abzeichen um meine Hilfe anzufordern.");
					return true;
					pPlayer->PlayerTalkClass->SendCloseGossip();
				}
			}break;

			case 1:{
                
                    pPlayer->TeleportTo(0, -7138.54, -4310.35, 264.33, 3.13);
                    pCreature->SummonCreature(800064, -7139.58, -4317.59, 264.33, 3.13, TEMPSUMMON_TIMED_DESPAWN, 120000);
					return true;
			}break;

				
		

			case 3:
			{
				pPlayer->GetGUID();
				ChatHandler(pPlayer->GetSession()).PSendSysMessage("[Boss System]\nOk, das ist Eure Sache ob ihr mich im Stich lasst!",
					pPlayer->GetName());
				pPlayer->PlayerTalkClass->SendCloseGossip();
				return true;
			}break;

			}
			return true;
		}
};




void AddSC_dark()
{
	new dark();
}