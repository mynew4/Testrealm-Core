#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include "GameEventMgr.h"

class eventnpc : public CreatureScript
{
public: eventnpc() : CreatureScript("eventnpc"){ }



		bool OnGossipHello(Player *pPlayer, Creature* _creature)
		{
			
			pPlayer->GetGUID();
			pPlayer->ADD_GOSSIP_ITEM(7, "Was tut dieser NPC?", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(7, "MMOwning Weihnachtsevent", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(7, "MMOwning Halloweenevent", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(7, "Exitares Spassevent", GOSSIP_SENDER_MAIN, 3);

			pPlayer->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
			return true;
		}


		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 /*uiSender*/, uint32 uiAction)
		{
			switch (uiAction)
			{
					
				case 1: {
					
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Wenn jetzt Weihnachten waere, wuerde ich dich zum Weihnachtsevent porten. Aber wir wissen beide, das es aktuell noch nicht soweit ist.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					//pPlayer->TeleportTo(1, 16226.21, 16256.77, 13.19, 1.65);
					return true;
				}break;
				
						
				case 0: {
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Dieser NPC zeigt an, welche Events von MMOwning gerade aktiv sind. Wenn keine Events aktiv sind, werden auch keine angezeigt.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}break;


				case 2:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Viel Spass beim Halloweenevent.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}break;

				case 3:
				{
					pPlayer->GetGUID();
					ChatHandler(pPlayer->GetSession()).PSendSysMessage("Das Spassevent von Exitare findet immer in der ersten Woche des Monats statt. Es gibt verschiedene Bonusbelohnungen sowie Spezialquests.",
						pPlayer->GetName());
					pPlayer->PlayerTalkClass->SendCloseGossip();
					return true;
				}break;

					return true;
			}
			return true;
		}
};


void AddSC_eventnpc()
{
	new eventnpc();
}