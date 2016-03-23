CREATE TABLE IF NOT EXISTS `spielerantworten` (
  `id` INT NOT NULL AUTO_INCREMENT COMMENT '',
  `spieler` VARCHAR(45) NULL COMMENT '',
  `playerid` INT NULL COMMENT '',
  `accountid` INT NULL COMMENT '',
  `anzahl` INT NULL COMMENT '',
  `richtig` INT NULL COMMENT '',
  `falsch` INT NULL COMMENT '',
  PRIMARY KEY (`id`)  COMMENT '');
