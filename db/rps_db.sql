/*
 Navicat Premium Data Transfer

 Source Server         : Local
 Source Server Type    : MySQL
 Source Server Version : 100126
 Source Host           : localhost:3306
 Source Schema         : rps_db

 Target Server Type    : MySQL
 Target Server Version : 100126
 File Encoding         : 65001

 Date: 06/02/2022 22:48:26
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for beats
-- ----------------------------
DROP TABLE IF EXISTS `beats`;
CREATE TABLE `beats`  (
  `item_id` int(5) UNSIGNED NOT NULL,
  `beats_id` int(5) UNSIGNED NOT NULL,
  INDEX `fk_item_id`(`item_id`) USING BTREE,
  INDEX `fk_beats_id`(`beats_id`) USING BTREE,
  CONSTRAINT `fk_item_id` FOREIGN KEY (`item_id`) REFERENCES `items` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `fk_beats_id` FOREIGN KEY (`beats_id`) REFERENCES `items` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of beats
-- ----------------------------
INSERT INTO `beats` VALUES (1, 4);
INSERT INTO `beats` VALUES (1, 4);
INSERT INTO `beats` VALUES (2, 5);
INSERT INTO `beats` VALUES (2, 5);
INSERT INTO `beats` VALUES (3, 4);
INSERT INTO `beats` VALUES (3, 4);
INSERT INTO `beats` VALUES (4, 5);
INSERT INTO `beats` VALUES (4, 5);
INSERT INTO `beats` VALUES (5, 1);
INSERT INTO `beats` VALUES (5, 1);

-- ----------------------------
-- Table structure for items
-- ----------------------------
DROP TABLE IF EXISTS `items`;
CREATE TABLE `items`  (
  `id` int(5) UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of items
-- ----------------------------
INSERT INTO `items` VALUES (1, 'Rock');
INSERT INTO `items` VALUES (2, 'Paper');
INSERT INTO `items` VALUES (3, 'Scissors');
INSERT INTO `items` VALUES (4, 'Lizard');
INSERT INTO `items` VALUES (5, 'Spock');

SET FOREIGN_KEY_CHECKS = 1;
