# ************************************************************
# Sequel Pro SQL dump
# Version 4541
#
# http://www.sequelpro.com/
# https://github.com/sequelpro/sequelpro
#
# Host: 127.0.0.1 (MySQL 5.6.35)
# Database: JeansCar
# Generation Time: 2018-01-30 14:27:50 +0000
# ************************************************************


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


# Dump of table Admin
# ------------------------------------------------------------

CREATE TABLE `Admin` (
  `A-code` varchar(10) NOT NULL DEFAULT '',
  `Pass` varchar(15) NOT NULL DEFAULT '' COMMENT 'min 6 ',
  `Add_employee` char(1) NOT NULL DEFAULT '0',
  `Salary` char(1) NOT NULL DEFAULT '0',
  `Stock` char(1) NOT NULL DEFAULT '0',
  `Manager` char(1) NOT NULL DEFAULT '0',
  `Deliver_salary` char(1) NOT NULL DEFAULT '0',
  `Custmers` char(1) NOT NULL DEFAULT '0',
  `Edit_Order` char(1) NOT NULL DEFAULT '0',
  `Ware` char(1) NOT NULL DEFAULT '0',
  `Open` char(1) NOT NULL DEFAULT '0',
  `Accounting` char(1) NOT NULL DEFAULT '0',
  `Deliver` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`A-code`),
  KEY `A-code` (`A-code`),
  CONSTRAINT `admin_ibfk_1` FOREIGN KEY (`A-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Attendence
# ------------------------------------------------------------

CREATE TABLE `Attendence` (
  `E-code` varchar(10) NOT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`E-code`,`Date`),
  CONSTRAINT `attendence_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Customer
# ------------------------------------------------------------

CREATE TABLE `Customer` (
  `Cnum` int(15) NOT NULL AUTO_INCREMENT,
  `Name` varchar(100) NOT NULL DEFAULT '',
  `Number` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`Cnum`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Daily
# ------------------------------------------------------------

CREATE TABLE `Daily` (
  `Dcode` bigint(20) NOT NULL AUTO_INCREMENT,
  `E-code` varchar(10) NOT NULL,
  `Amount` double NOT NULL,
  `Reason` varchar(200) NOT NULL,
  `Date` date NOT NULL,
  `Income` char(1) NOT NULL DEFAULT '0',
  `Done` char(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`Dcode`),
  KEY `E-code` (`E-code`),
  CONSTRAINT `daily_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Delay-time
# ------------------------------------------------------------

CREATE TABLE `Delay-time` (
  `E-code` varchar(10) NOT NULL,
  `Amount` double NOT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`E-code`,`Date`),
  KEY `E-code` (`E-code`),
  CONSTRAINT `delay-time_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Drag
# ------------------------------------------------------------

CREATE TABLE `Drag` (
  `E-code` varchar(10) NOT NULL,
  `C-type` varchar(20) NOT NULL,
  `C-color` varchar(15) NOT NULL,
  `Price` double NOT NULL,
  `Quantity` double NOT NULL,
  `Notes` varchar(200) DEFAULT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`Date`),
  KEY `C-type` (`C-type`,`C-color`),
  KEY `drag_ibfk_3_idx` (`E-code`),
  CONSTRAINT `drag_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `drag_ibfk_2` FOREIGN KEY (`C-type`, `C-color`) REFERENCES `Ware` (`Ctype`, `Ccolor`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table employee
# ------------------------------------------------------------

CREATE TABLE `employee` (
  `Ecode` varchar(10) NOT NULL DEFAULT '',
  `Name` varchar(100) NOT NULL DEFAULT '',
  `Nation-id` varchar(14) NOT NULL DEFAULT '',
  `Social-status` varchar(10) NOT NULL DEFAULT '',
  `BirthDate` date NOT NULL,
  `Number` varchar(13) NOT NULL DEFAULT '',
  `Home_Num` varchar(13) DEFAULT NULL,
  `Add-nid` varchar(200) NOT NULL DEFAULT '',
  `Add-ano` varchar(200) DEFAULT NULL,
  `Clear-salary` double NOT NULL,
  `Last_salaray` double DEFAULT NULL,
  `Hours` double NOT NULL,
  `Arrive-time` time NOT NULL,
  `Leave-time` time NOT NULL,
  `Major` varchar(20) DEFAULT NULL,
  `Certifcate` varchar(100) DEFAULT NULL,
  `Year_grad` date DEFAULT NULL,
  `Year_of_job` date NOT NULL,
  `Curr_job` varchar(100) DEFAULT '',
  `N_of_work_in_years` double NOT NULL,
  `Another_exper` varchar(100) DEFAULT NULL,
  `Insurance` char(1) NOT NULL DEFAULT '',
  `Weakly` char(1) NOT NULL DEFAULT '',
  `Note` varchar(200) DEFAULT NULL,
  `Min` double DEFAULT NULL,
  PRIMARY KEY (`Ecode`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Flat_colors
# ------------------------------------------------------------

CREATE TABLE `Flat_colors` (
  `Color` varchar(30) NOT NULL DEFAULT '',
  PRIMARY KEY (`Color`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Modify-salary
# ------------------------------------------------------------

CREATE TABLE `Modify-salary` (
  `A-code` varchar(10) NOT NULL,
  `E-code` varchar(10) NOT NULL,
  `Amount` double NOT NULL,
  `Date` datetime NOT NULL,
  `Notes` varchar(200) NOT NULL,
  `Type` char(1) NOT NULL DEFAULT '',
  `New_salary` double NOT NULL,
  PRIMARY KEY (`E-code`,`Date`),
  KEY `E-code` (`E-code`),
  KEY `A-code` (`A-code`),
  CONSTRAINT `modify-salary_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `modify-salary_ibfk_2` FOREIGN KEY (`A-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Mohafzat
# ------------------------------------------------------------

CREATE TABLE `Mohafzat` (
  `Date` date NOT NULL,
  `C_Name` varchar(60) NOT NULL DEFAULT '',
  `Number` varchar(15) NOT NULL DEFAULT '',
  `Car` varchar(100) NOT NULL DEFAULT '',
  `M_name` varchar(30) NOT NULL DEFAULT '',
  `Time` time NOT NULL,
  PRIMARY KEY (`Date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Monthly
# ------------------------------------------------------------

CREATE TABLE `Monthly` (
  `Date` date NOT NULL,
  `Total_income` double NOT NULL DEFAULT '0',
  `Total_outcome` double NOT NULL DEFAULT '0',
  `Profit` double NOT NULL DEFAULT '0',
  `Total_ware` double NOT NULL DEFAULT '0',
  `Total_stock` double NOT NULL DEFAULT '0',
  `stock_cost` double NOT NULL DEFAULT '0',
  `ware_cost` double NOT NULL DEFAULT '0',
  `Opnums` int(11) NOT NULL DEFAULT '0',
  `Employee_cost` double NOT NULL DEFAULT '0',
  PRIMARY KEY (`Date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Note
# ------------------------------------------------------------

CREATE TABLE `Note` (
  `A-code` varchar(10) NOT NULL,
  `E-code` varchar(10) NOT NULL,
  `Date` datetime NOT NULL,
  `Notes` varchar(300) NOT NULL,
  PRIMARY KEY (`E-code`,`Date`),
  KEY `E-code` (`E-code`),
  KEY `A-code` (`A-code`),
  CONSTRAINT `note_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `note_ibfk_2` FOREIGN KEY (`A-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Order
# ------------------------------------------------------------

CREATE TABLE `Order` (
  `Order-num` int(15) NOT NULL AUTO_INCREMENT,
  `A-code` varchar(10) NOT NULL,
  `C-code` int(15) NOT NULL,
  `Car-det` varchar(100) NOT NULL DEFAULT '',
  `Total-price` double NOT NULL,
  `M-Pay` double NOT NULL,
  `M-Remain` double NOT NULL,
  `Order-time` date NOT NULL,
  `Delvtime` date NOT NULL,
  `Order` varchar(300) NOT NULL,
  `Done` tinyint(1) NOT NULL,
  `Bouns` tinyint(1) DEFAULT '0',
  `time` char(1) NOT NULL,
  `Moagal` tinyint(1) NOT NULL DEFAULT '0',
  `stamp` varchar(40) DEFAULT NULL,
  `cur` int(11) NOT NULL DEFAULT '0',
  `flat` char(1) NOT NULL DEFAULT '0',
  `wheel` char(1) NOT NULL DEFAULT '0',
  `flat_color` varchar(15) NOT NULL DEFAULT 'لا يوجد',
  `Warn` int(11) NOT NULL DEFAULT '5',
  PRIMARY KEY (`Order-num`),
  KEY `C-code` (`C-code`),
  KEY `A-code` (`A-code`),
  CONSTRAINT `order_ibfk_1` FOREIGN KEY (`C-code`) REFERENCES `Customer` (`Cnum`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `order_ibfk_2` FOREIGN KEY (`A-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Produce
# ------------------------------------------------------------

CREATE TABLE `Produce` (
  `A-code` varchar(10) NOT NULL,
  `E-code` varchar(10) NOT NULL,
  `Amount` double NOT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`E-code`,`Date`),
  KEY `E-code` (`E-code`),
  KEY `A-code` (`A-code`),
  CONSTRAINT `produce_ibfk_1` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `produce_ibfk_2` FOREIGN KEY (`A-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Salary
# ------------------------------------------------------------

CREATE TABLE `Salary` (
  `E-code` varchar(10) NOT NULL,
  `Date` date NOT NULL,
  `Amount` double NOT NULL,
  `Done` tinyint(1) NOT NULL,
  PRIMARY KEY (`E-code`,`Date`),
  CONSTRAINT `E-code` FOREIGN KEY (`E-code`) REFERENCES `employee` (`Ecode`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Sec
# ------------------------------------------------------------

CREATE TABLE `Sec` (
  `Date` date NOT NULL,
  `H11` int(15) DEFAULT NULL,
  `H11a` int(15) DEFAULT NULL,
  `H11b` int(15) DEFAULT NULL,
  `H11c` int(15) DEFAULT NULL,
  `H11d` int(15) DEFAULT NULL,
  `H11e` int(15) DEFAULT NULL,
  `H2` int(15) DEFAULT NULL,
  `H2a` int(15) DEFAULT NULL,
  `H2b` int(15) DEFAULT NULL,
  `H2c` int(15) DEFAULT NULL,
  `H2d` int(15) DEFAULT NULL,
  `H2e` int(15) DEFAULT NULL,
  `H5` int(15) DEFAULT NULL,
  `H5a` int(15) DEFAULT NULL,
  `H5b` int(15) DEFAULT NULL,
  `H5c` int(15) DEFAULT NULL,
  `H5d` int(15) DEFAULT NULL,
  `H5e` int(15) DEFAULT NULL,
  PRIMARY KEY (`Date`),
  KEY `H11` (`H11`),
  KEY `H11a` (`H11a`),
  KEY `H11b` (`H11b`),
  KEY `H2` (`H2`),
  KEY `H2a` (`H2a`),
  KEY `H2b` (`H2b`),
  KEY `H5` (`H5`),
  KEY `H5a` (`H5a`),
  KEY `H5b` (`H5b`),
  KEY `H11c` (`H11c`),
  KEY `H11d` (`H11d`),
  KEY `H11e` (`H11e`),
  KEY `H2c` (`H2c`),
  KEY `H2d` (`H2d`),
  KEY `H2e` (`H2e`),
  KEY `H5c` (`H5c`),
  KEY `H5d` (`H5d`),
  KEY `H5e` (`H5e`),
  CONSTRAINT `sec_ibfk_1` FOREIGN KEY (`H11`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_10` FOREIGN KEY (`H11c`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_11` FOREIGN KEY (`H11d`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_12` FOREIGN KEY (`H11e`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_13` FOREIGN KEY (`H2c`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_14` FOREIGN KEY (`H2d`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_15` FOREIGN KEY (`H2e`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_16` FOREIGN KEY (`H5c`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_17` FOREIGN KEY (`H5d`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_18` FOREIGN KEY (`H5e`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_2` FOREIGN KEY (`H11a`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_3` FOREIGN KEY (`H11b`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_4` FOREIGN KEY (`H2`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_5` FOREIGN KEY (`H2a`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_6` FOREIGN KEY (`H2b`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_7` FOREIGN KEY (`H5`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_8` FOREIGN KEY (`H5a`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `sec_ibfk_9` FOREIGN KEY (`H5b`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Settings
# ------------------------------------------------------------

CREATE TABLE `Settings` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `Flats` int(11) NOT NULL DEFAULT '5',
  `Wheels` int(11) NOT NULL DEFAULT '2',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Stamp
# ------------------------------------------------------------

CREATE TABLE `Stamp` (
  `Scode` varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (`Scode`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Status
# ------------------------------------------------------------

CREATE TABLE `Status` (
  `O-num` int(15) NOT NULL,
  `Status` char(1) NOT NULL DEFAULT '',
  PRIMARY KEY (`O-num`),
  CONSTRAINT `status_ibfk_1` FOREIGN KEY (`O-num`) REFERENCES `Order` (`Order-num`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Stock
# ------------------------------------------------------------

CREATE TABLE `Stock` (
  `Scode` int(15) NOT NULL AUTO_INCREMENT,
  `Name` varchar(30) NOT NULL,
  `Quantity` double NOT NULL,
  `Price` double NOT NULL,
  `Source` varchar(45) NOT NULL,
  `Date` date NOT NULL,
  PRIMARY KEY (`Scode`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;



# Dump of table Ware
# ------------------------------------------------------------

CREATE TABLE `Ware` (
  `Ctype` varchar(20) NOT NULL,
  `Ccolor` varchar(15) NOT NULL,
  `Name` varchar(30) DEFAULT '',
  `Price` double NOT NULL,
  `Quantity` int(7) NOT NULL,
  PRIMARY KEY (`Ctype`,`Ccolor`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;




/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
