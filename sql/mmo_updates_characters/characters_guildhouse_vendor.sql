/* Records Guildhouse CharDB */

CREATE TABLE IF NOT EXISTS `guildhouses` (
  `id` int(16) unsigned NOT NULL AUTO_INCREMENT,
  `guildId` bigint(20) NOT NULL DEFAULT '0',
  `x` float NOT NULL,
  `y` float NOT NULL,
  `z` float NOT NULL,
  `map` int(16) NOT NULL,
  `comment` varchar(255) NOT NULL DEFAULT '',
  `price` bigint(20) NOT NULL DEFAULT '1000000000',
  `faction` int(8) unsigned NOT NULL DEFAULT '3',
  `minguildsize` int(16) unsigned NOT NULL DEFAULT '10',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC AUTO_INCREMENT=45 ;


INSERT INTO `guildhouses` (`id`, `guildId`, `x`, `y`, `z`, `map`, `comment`, `price`, `faction`, `minguildsize`) VALUES
(1, 0, 16222, 16266, 14.2, 1, 'GM Island', 100000, 3, 10),
(2, 33, -10711, 2483, 8, 1, 'Tauren village at Veiled Sea (Silithus)', 100000, 3, 10),
(3, 30, -8269, -223, 268, 0, 'Fishing outside an Northshire Abbey (Elwynn Forest', 100000, 3, 10),
(4, 0, 7368, -1560, 163, 1, 'Troll Village in mountains (Darkshore)', 100000, 3, 10),
(5, 0, -4151, -1400, 198, 0, 'Dwarven village outside Ironforge (Wetlands)', 100000, 3, 10),
(6, 0, -1840, -4233, 2.14, 0, 'Dwarven village (Arathi Highlands, Forbidding Sea)', 100000, 3, 10),
(7, 0, -723, -1076, 179, 1, 'Tauren camp (Mulgore, Red Rock)', 100000, 3, 10),
(8, 0, -206, 1666, 80, 0, 'Shadowfang Keep an outside instance (Silverpine Forest)', 100000, 3, 10),
(9, 0, -6374, 1262, 7, 0, 'Harbor house outside Stormwind (Elwynn Forest)', 100000, 3, 10),
(10, 0, -8640, 580, 96, 0, 'Empty jail between canals (Stormwind)', 100000, 3, 10),
(11, 0, -4816.41, -1034.19, 438.683, 0, 'Old Ironforge', 100000, 3, 10),
(12, 0, -4863, -1658, 503.5, 0, 'Ironforge Airport', 100000, 3, 10),
(13, 0, 1000.69, 280.002, 326.399, 37, 'Azshara Crater instance (Alliance entrance)', 100000, 3, 10),
(14, 0, 155.683, 979.871, 294.492, 37, 'Azshara Crater instance (Horde entrance)', 100000, 3, 10),
(15, 0, 4303, -2760, 16.8, 0, 'Quel''Thalas Tower', 100000, 3, 10),
(16, 0, -6161, -790, 423, 0, 'Crashed gnome airplane (between Dun Morogh and Searing Gorge)', 100000, 3, 10),
(17, 0, -12284.6, -1906.97, 130.269, 0, 'Zul''Gurub an outside instance (Stranglethorn Vale)', 100000, 3, 10),
(18, 46, -11805, -4754, 6, 1, 'Goblin village (Tanaris, South Seas)', 100000, 3, 10),
(19, 0, -9296, 670, 132, 0, 'Villains camp outside an Stormwind (Elwynn Forest)', 100000, 3, 10),
(20, 0, 3414, -3380, 142.2, 0, 'Stratholm an outside instance', 100000, 3, 10),
(21, 0, 4654, -3772, 944, 1, 'Kalimdor Hyjal (Aka World Tree)', 100000, 3, 10),
(22, 0, 2176, -4766, 55, 1, 'The Ring of Valor (Aka. Orgrimmar Arena)', 100000, 3, 10),
(23, 0, 1951.51, 1530.48, 247.288, 1, 'Stonetalon Logging Camp', 100000, 3, 10),
(24, 0, 2813.66, 2248.55, 215.525, 1, 'Stonetalon Ruins', 100000, 3, 10),
(25, 0, 9725.27, -21.43, 20.03, 1, 'Teldrassil Furbold camp', 100000, 3, 10),
(26, 0, -3855, -3479, 579, 0, 'Wetlands mountain camp', 100000, 3, 10),
(27, 0, -5362, -2540, 485, 0, 'Ortell''s Hideout', 100000, 3, 10),
(28, 0, -13014.7, -1338.5, 49.8596, 0, 'Stranglethorn Secret Cave', 100000, 3, 10),
(29, 0, -11073, -1956, 39, 0, 'Karazhan Smiley', 100000, 3, 10),
(30, 0, -11084, -1801, 53, 0, 'Well of the Forgotten (Aka. Karazhan Crypt or Lower Karazhan)', 100000, 3, 10),
(31, 0, 1683.24, 286.459, -45.4518, 0, 'Undercity Top Tier', 100000, 3, 10),
(32, 0, -8521.3, 599.5, 101.399, 0, 'Stormwind Cut-Throat Alley', 100000, 3, 10),
(33, 0, -5894.12, 657.519, 489.254, 0, 'Forgotten gnome camp', 100000, 3, 10),
(34, 0, -2140.5, 9142.69, 137.042, 530, 'Outland Nagrand : Tomb', 100000, 3, 10),
(35, 0, -483.402, 7461.94, 186.121, 530, 'Outland Nagrand: Challe''s Home for Little Tykes', 100000, 3, 10),
(36, 0, 2387.75, 3191.76, 152.669, 530, 'Outland Netherstorm: Nova''s Shrine', 100000, 3, 10),
(37, 0, -8635.55, -538.484, 145.781, 0, 'Wald von Elwynn', 100000, 3, 10),
(38, 0, 7368, -1560, 163, 1, 'Troll Village in mountains 2 (Darkshore)', 100000, 3, 10);

CREATE TABLE IF NOT EXISTS `guildhouses_add` (
  `guid` int(32) unsigned NOT NULL,
  `type` int(16) unsigned NOT NULL,
  `id` int(16) unsigned NOT NULL,
  `add_type` int(16) unsigned NOT NULL,
  `comment` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;


CREATE TABLE IF NOT EXISTS `guildhouses_addtype` (
  `add_type` int(16) unsigned NOT NULL,
  `comment` varchar(255) NOT NULL DEFAULT '',
  `price` bigint(20) NOT NULL DEFAULT '1000',
  `minguildsize` int(16) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`add_type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

CREATE TABLE IF NOT EXISTS `gh_guildadd` (
  `guildId` int(32) unsigned NOT NULL,
  `GuildHouse_Add` int(32) unsigned NOT NULL,
  PRIMARY KEY (`guildId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;