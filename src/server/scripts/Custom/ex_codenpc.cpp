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






class codenpc : public CreatureScript
{
 

public:
    codenpc() : CreatureScript("codenpc") { }
    
    void Belohnung(Player* player, std::string codes){
        
		PreparedStatement* selantwort = CharacterDatabase.GetPreparedStatement(CHAR_SEL_ANTWORTEN_NACH_ANTWORT);
		selantwort->setString(0, codes);
		PreparedQueryResult ergebnis = CharacterDatabase.Query(selantwort);
		
		if (!ergebnis){
			player->GetSession()->SendNotification("Deine Antwort ist nicht korrekt!");
		}

		Field* felder = ergebnis->Fetch();
		uint32 belohnung = felder.GetInt32();
		uint32 anzahl = felder.GetInt32();

		if (ergebnis){
			Item* item = Item::CreateItem(belohnung, anzahl);
			player->GetSession()->SendNotification("Dein Code wurde generiert und die Belohnung zugesendet!");
			SQLTransaction trans = CharacterDatabase.BeginTransaction();
			item->SaveToDB(trans);
			MailDraft("Dein Gutscheincode", "Dein Code wurde erfolgreich eingeloest. Wir wuenschen dir weiterhin viel Spass auf MMOwning. Dein MMOwning-Team").AddItem(item)
				.SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
			CharacterDatabase.CommitTransaction(trans);
			player->GetSession()->SendNotification("Deine Antwort war korrekt. Deine Belohnung wurde zugesandt.");
		}

    }
    
    
   
    bool OnGossipHello(Player *player, Creature* _creature)
    {
        player->ADD_GOSSIP_ITEM_EXTENDED(7, "Bitte gib deine Antwort ein!" , GOSSIP_SENDER_MAIN, 2, "Deine Antwort lautet: ", 0,true);
        player->PlayerTalkClass->SendGossipMenu(907, _creature->GetGUID());
        return true;
    }
    
    
    bool OnGossipSelectCode(Player * player, Creature* /*creature*/, uint32 /*sender*/, uint32 action, const char* code){
        
        switch(action){
            
            
            case 2:
                {
                
                    std::string codes = code;
                
                    if(codes == "Easteregg"){
                        player->GetSession()->SendNotification("Viel Spass mit dem Easteregg");
                        return true;
                    }
                    
					Belohnung(player->GetSession()->GetPlayer(), codes);

                    
                    
                    if(!ergebnis){
                        player->GetSession()->SendNotification("Falsch");
                        return false;
                    }
                    
                    
                    Field* feld = ergebnis->Fetch();
                    uint32 nr = feld[0].GetInt32();
                    
                    if(ergebnis){ 
						player->GetSession()->SendNotification("Antwort wurde gefunden");
                        Belohnung(player->GetSession()->GetPlayer(), nr);
                        return true;
                    }
                    
                    
                
                }break;
        
                return true;
        
            }
    
        return true;
    }
    
};


void AddSC_codenpc()
{
    new codenpc();
}