SET
@ID1    := 800534,
@ID2    := 800514,
@ID3    := 800515,
@ID4    := 800516,
@ID5    := 800517,
@ID6    := 800518,
@ID7    := 800519,
@ID8    := 800520,
@ID9    := 800521,
@ID10    := 800522,
@ID11    := 800523,
@ID12    := 800524,
@ID13    := 800525,
@ID14    := 800526,
@ID15    := 800527,
@ID16    := 800528,
@ID17    := 800529,
@ID18    := 800530,
@ID19    := 800531,
@ID20    := 800532,
@ID21    := 800533;


REPLACE INTO `quest_template` (`ID`, `Method`, `QuestLevel`, `MinLevel`, `QuestSortID`, `QuestType`, `SuggestedGroupNum`, `LimitTime`, `RequiredRaces`, `RequiredFactionId1`, `RequiredFactionId2`, `RequiredFactionValue1`, `RequiredFactionValue2`, `NextQuestIdChain`, `RewardXPId`, `RewardOrRequiredMoney`, `RewardMoneyMaxLevel`, `RewardSpell`, `RewardSpellCast`, `RewardHonor`, `RewardHonorMultiplier`, `SourceItemId`, `Flags`, `RewardTitle`, `RequiredPlayerKills`, `RewardTalents`, `RewardArenaPoints`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `PointMapId`, `PointX`, `PointY`, `PointOption`, `LogTitle`, `LogDescription`, `QuestDescription`, `EndText`, `OfferRewardText`, `RequestItemsText`, `QuestCompletionLog`, `RequiredNpcOrGo1`, `RequiredNpcOrGo2`, `RequiredNpcOrGo3`, `RequiredNpcOrGo4`, `RequiredNpcOrGoCount1`, `RequiredNpcOrGoCount2`, `RequiredNpcOrGoCount3`, `RequiredNpcOrGoCount4`, `RequiredSourceItemId1`, `RequiredSourceItemId2`, `RequiredSourceItemId3`, `RequiredSourceItemId4`, `RequiredSourceItemCount1`, `RequiredSourceItemCount2`, `RequiredSourceItemCount3`, `RequiredSourceItemCount4`, `RequiredItemId1`, `RequiredItemId2`, `RequiredItemId3`, `RequiredItemId4`, `RequiredItemId5`, `RequiredItemId6`, `RequiredItemCount1`, `RequiredItemCount2`, `RequiredItemCount3`, `RequiredItemCount4`, `RequiredItemCount5`, `RequiredItemCount6`, `Unknown0`, `ObjectiveText1`, `ObjectiveText2`, `ObjectiveText3`, `ObjectiveText4`, `DetailsEmote1`, `DetailsEmote2`, `DetailsEmote3`, `DetailsEmote4`, `DetailsEmoteDelay1`, `DetailsEmoteDelay2`, `DetailsEmoteDelay3`, `DetailsEmoteDelay4`, `EmoteOnIncomplete`, `EmoteOnComplete`, `OfferRewardEmote1`, `OfferRewardEmote2`, `OfferRewardEmote3`, `OfferRewardEmote4`, `OfferRewardEmoteDelay1`, `OfferRewardEmoteDelay2`, `OfferRewardEmoteDelay3`, `OfferRewardEmoteDelay4`, `VerifiedBuild`) VALUES
 
 
 (@ID1,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Eiskronenzitadelle','T�tet den Lichk�nig in der Eiskronenzitadelle. Ihr werdet reich belohnt werden !',0,0,0,0,0,36597,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID2,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Ulduar','T�tet Freya in Ulduar. Ihr werdet reich belohnt werden !',0,0,0,0,0,32906,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID3,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Naxxramas','T�tet Kel\Thuzad in Naxxramas. Ihr werdet reich belohnt werden !',0,0,0,0,0,15990,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID4,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Archavons Kammer','T�tet Toravon der Eisw�chter in Archavons Kammer. Ihr werdet reich belohnt werden !',0,0,0,0,0,31125,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID5,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Pr�fung des Kreuzfahrers','T�tet Anub\arak in der Pr�fung des Kreuzfahrers. Ihr werdet reich belohnt werden !',0,0,0,0,0,34564,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID6,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Das Obsidiansanktum','T�tet Sartharion im Obsidiansanktum. Ihr werdet reich belohnt werden !',0,0,0,0,0,28860,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID7,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Das Auge der Ewigkeit','T�tet Malygos im Auge der Ewigkeit. Ihr werdet reich belohnt werden !',0,0,0,0,0,28859,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID8,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Das Rubinsanktum','T�tet Halion im Rubinsanktum. Ihr werdet reich belohnt werden !',0,0,0,0,0,39863,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID9,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Onyxias Hort','T�tet Onyxia in Onyxias Hort. Ihr werdet reich belohnt werden !',0,0,0,0,0,10184,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID10,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Der Schwarze Tempel','T�tet Illidan im schwarzen Tempel. Ihr werdet reich belohnt werden !',0,0,0,0,0,22917,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID11,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Festung der St�rme','T�tet Kael\Thas in der Festung der St�rme. Ihr werdet reich belohnt werden !',0,0,0,0,0,19622,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID12,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Hyjalgipfel','T�tet Archimonde im Hyjalgipfel. Ihr werdet reich belohnt werden !',0,0,0,0,0,17968,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID13,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: H�hle des Schlangenschreins','T�tet Lady Vashj in der H�hle des Schlangenschreins. Ihr werdet reich belohnt werden !',0,0,0,0,0,21212,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID14,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Magtheridons Kammer','T�tet Magtheridon in Magtheridons Kammer. Ihr werdet reich belohnt werden !',0,0,0,0,0,17257,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID15,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,1,2,0,0,38186,0,0,0,0,0,1,0,0,0,'|cff3B0B2EWeekly: Gruuls Unterschlupf','T�tet Gruuls in Gruuls Unterschlupf. Ihr werdet reich belohnt werden !',0,0,0,0,0,19044,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID16,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Karazhan','T�tet Malchezaar in Karazhan. Ihr werdet reich belohnt werden !',0,0,0,0,0,15690,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID17,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Geschmolzener Kern','T�tet Ragnaros im Geschmolzener Kern. Ihr werdet reich belohnt werden !',0,0,0,0,0,11502,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID18,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Pechschwingenhort','T�tet Nefarian im Pechschwingenhort. Ihr werdet reich belohnt werden !',0,0,0,0,0,11583,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID19,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Ahn\Qiraj','T�tet C\Thun in Ahn\Qiraj. Ihr werdet reich belohnt werden !',0,0,0,0,0,15727,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID20,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Ruinen von Ahn\Qiraj','T�tet Ossirian in den Ruinen von Ahn\Qiraj. Ihr werdet reich belohnt werden !',0,0,0,0,0,15339,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0),
 (@ID21,2,80,80,200000,32840,0,0,0,0,0,49426,47241,0,0,2,4,0,0,38186,0,0,0,0,0,2,0,0,0,'|cff3B0B2EWeekly: Zul\Gurub','T�tet Hakkar in Zul\Gurub. Ihr werdet reich belohnt werden !',0,0,0,0,0,14834,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
 
 
 
 
 REPLACE INTO `creature_questender` VALUES
(800013, @ID1),
(800013, @ID2),
(800013, @ID3),
 (800013, @ID4),
 (800013, @ID5),
 (800013, @ID6),
 (800013, @ID7),
 (800013, @ID8),
 (800013, @ID9),
 (800013, @ID10),
 (800013, @ID11),
 (800013, @ID12),
 (800013, @ID13),
 (800013, @ID14),
 (800013, @ID15),
 (800013, @ID16),
 (800013, @ID17),
 (800013, @ID18),
 (800013, @ID19), 
 (800013, @ID20),  
 (800013, @ID21);  
 
  
 REPLACE INTO `creature_queststarter` VALUES
(800013, @ID1),
(800013, @ID2),
(800013, @ID3),
 (800013, @ID4),
 (800013, @ID5),
 (800013, @ID6),
 (800013, @ID7),
 (800013, @ID8),
 (800013, @ID9),
 (800013, @ID10),
 (800013, @ID11),
 (800013, @ID12),
 (800013, @ID13),
 (800013, @ID14),
 (800013, @ID15),
 (800013, @ID16),
 (800013, @ID17),
 (800013, @ID18),
 (800013, @ID19), 
 (800013, @ID20),  
 (800013, @ID21);  
