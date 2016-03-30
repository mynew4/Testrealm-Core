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
    
    void Belohnung(Player* player, uint32 nr){
        
		PreparedStatement* itemquery = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN_NACH_NR);
		itemquery->setInt32(0, nr);
		PreparedQueryResult result = CharacterDatabase.Query(itemquery);
		if (result){
			player->GetSession()->SendNotification("Frage wurde gefunden");
		}

		if (!result){
			player->GetSession()->SendNotification("Es gab keinen Treffer");
		}

		else {
			player->GetSession()->SendNotification("Ein Fehler ist aufgetreten. Setze dich bitte mit den Administratoren in Verbindung.");
		}

		/*
        PreparedStatement * account = CharacterDatabase.GetPreparedStatement(CHAR_SEL_BEANTWORTET);
		account->setInt32(0, player->GetSession()->GetAccountId());
        account->setInt32(1, nr);
        PreparedQueryResult ergebnis = CharacterDatabase.Query(account);
        
        if(!ergebnis){
            PreparedStatement* itemquery = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN_NACH_NR);
            itemquery->setInt32(0, nr);
            PreparedQueryResult result = CharacterDatabase.Query(itemquery);
            
            Field* feld = result->Fetch();
            uint32 belohnung = feld[4].GetInt32();
            uint32 anzahl = feld[5].GetInt32();
            
            Item* item = Item::CreateItem(belohnung, anzahl);
            SQLTransaction trans = CharacterDatabase.BeginTransaction();
            item->SaveToDB(trans);
            MailDraft("Raetsel geloest", "Glueckwunsch. Du hast ein Raetsel geloest. Hier ist deine Belohnung.").AddItem(item)
            .SendMailTo(trans, MailReceiver(player, player->GetGUID()), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM));
            CharacterDatabase.CommitTransaction(trans);
            
            
			PreparedStatement * accountinsert = CharacterDatabase.GetPreparedStatement(CHAR_INS_BEANTWORTET);
            accountinsert->setInt32(0, player->GetSession()->GetAccountId());
            accountinsert->setInt32(1, nr);
            CharacterDatabase.Execute(accountinsert);
            return;
        }
        
        else{
            player->GetSession()->SendNotification("Du hast dieses Raetsel schon beantwortet und kannst es daher nicht mehr beantworten.");
            return;
        }
		*/
       
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
                    
                    PreparedStatement* selantwort = CharacterDatabase.GetPreparedStatement(CHAR_SEL_FRAGEN_NACH_ANTWORT);
                    selantwort->setString(0, codes);
                    PreparedQueryResult ergebnis = CharacterDatabase.Query(selantwort);
                    
                    if(!ergebnis){
                        player->GetSession()->SendNotification("Falsch");
                        return false;
                    }
                    
                    
                    Field* feld = ergebnis->Fetch();
                    uint32 nr = feld[0].GetInt32();
                    
                    
                    if(ergebnis){ 
						player->GetSession()->SendNotification("Antwort wurde gefunden");
                        Belohnung(player->GetSession()->GetPlayer(), nr);
						player->GetSession()->SendNotification(nr);
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