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

enum PlayerMovementType
{
Speed
};

class goldaufbank : public PlayerScript
{

public:
	goldaufbank() : PlayerScript("goldaufbank") { }


	void OnMoneyChanged(Player* pPlayer, int32& gGold)
	{
		bool elite = pPlayer->GetSession()->IsPremium();
		uint32 gildenid = pPlayer->GetGuildId();

		if (gildenid == 0)
		{
			return;
		}

		else
		{
			if (!elite)
			{

				QueryResult ergebnis;
				ergebnis = CharacterDatabase.PQuery("Select bankmoney from `guild` where `guildid` = '%u'", gildenid);
				Field *feld = ergebnis->Fetch();
				uint32 bankmoney = feld[0].GetUInt32();

				uint32 zusatzbetrag = gGold * 0.10;

				uint32 neubetrag = bankmoney + zusatzbetrag;

				CharacterDatabase.PExecute("UPDATE guild SET `bankmoney` = '%u' WHERE `guildid` = '%u'", neubetrag, gildenid);

			}

			else
			{

				QueryResult ergebnis;
				ergebnis = CharacterDatabase.PQuery("Select bankmoney from `guild` where `guildid` = '%u'", gildenid);
				Field *feld = ergebnis->Fetch();
				uint32 bankmoney = feld[0].GetUInt32();

				uint32 zusatzbetrag = gGold * 0.20;

				uint32 neubetrag = bankmoney + zusatzbetrag;

				CharacterDatabase.PExecute("UPDATE guild SET `bankmoney` = '%u' WHERE `guildid` = '%u'", neubetrag, gildenid);

			}

			return;
		}

	}
}; 


// Speed wieder normal setzen?
class totlaufen : public PlayerScript
{

public:
	totlaufen() : PlayerScript("totlaufen") { }

	void tot(Player* pPlayer)
	{
		uint32 gildenid = pPlayer->GetGuildId();
		if (gildenid == 0)
		{
			return;
		}
		else
		{
			if (pPlayer->isDead == true)
			{
				if (pPlayer->GetSession()->IsPremium() == true)
				{
					pPlayer->SetSpeed(MOVE_RUN, 4, true);
				}

				else
				{
					pPlayer->SetSpeed(MOVE_RUN, 4, true);
				}

			}

			return;
		}

	}
};


class ruhestein : public PlayerScript
{

public:
	ruhestein() : PlayerScript("ruhestein") { }

	void cd_ruhestein(Player* pPlayer)
	{
		if (pPlayer->HasItemCount(6948, 1, true))
		{
			pPlayer->SetRuneCooldown(6948, );
		}

		else
		{
			return;
		}
	}

};



class X : public PlayerScript
{

public:
	X() : PlayerScript("X") { }

};



void AddSC_sb_uebung()
{
	new goldaufbank();
	new totlaufen();
}

