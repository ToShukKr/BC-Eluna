/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _ELUNA_INCLUDES_H
#define _ELUNA_INCLUDES_H

// Required
#include "Accounts/AccountMgr.h"
#include "AuctionHouse/AuctionHouseMgr.h"
#include "Grids/Cell.h"
#include "Grids/CellImpl.h"
#include "Chat/Chat.h"
#include "Chat/Channel.h"
#include "Server/DBCStores.h"
#include "Entities/GossipDef.h"
#include "Grids/GridNotifiers.h"
#include "Grids/GridNotifiersImpl.h"
#include "Groups/Group.h"
#include "Guilds/Guild.h"
#include "Guilds/GuildMgr.h"
#include "Tools/Language.h"
#include "Mails/Mail.h"
#include "Maps/MapManager.h"
#include "Globals/ObjectAccessor.h"
#include "Globals/ObjectMgr.h"
#include "Server/Opcodes.h"
#include "Entities/Player.h"
#include "Entities/Pet.h"
#include "Reputation/ReputationMgr.h"
#include "DBScripts/ScriptMgr.h"
#include "Spells/Spell.h"
#include "Spells/SpellAuras.h"
#include "Spells/SpellMgr.h"
//#include "TemporarySummon.h"
#include "WorldPacket.h"
#include "Server/WorldSession.h"

#ifdef TRINITY
#include "Config.h"
#include "GroupMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "WeatherMgr.h"
#include "Battleground.h"
#include "GitRevision.h"
#include "SpellHistory.h"
#else
#include "Config/Config.h"
#ifdef CMANGOS
//#include "AI/AggressorAI.h"
#else
#include "AggressorAI.h"
#endif
#include "BattleGround/BattleGroundMgr.h"
#include "Server/SQLStorages.h"
#include "revision.h"
#endif

#if (!defined(TBC) && !defined(CLASSIC))
#include "Vehicle.h"
#endif

#ifndef CLASSIC
#include "ArenaTeam.h"
#endif

#ifndef CLASSIC
typedef Opcodes                 OpcodesList;
#endif

/*
 * Note: if you add or change a CORE_NAME or CORE_VERSION #define,
 *   please update LuaGlobalFunctions::GetCoreName or LuaGlobalFunctions::GetCoreVersion documentation example string.
 */
#ifdef MANGOS
#define CORE_NAME               "MaNGOS"
#define CORE_VERSION            REVISION_NR
#endif

#ifdef CMANGOS
#define CORE_NAME               "cMaNGOS"
#define CORE_VERSION            REVISION_DATE " " REVISION_TIME
#endif

#ifdef TRINITY
#define CORE_NAME               "TrinityCore"
#define CORE_VERSION            (GitRevision::GetDate())
#define eWorld                  (sWorld)
#define eMapMgr                 (sMapMgr)
#define eConfigMgr              (sConfigMgr)
#define eGuildMgr               (sGuildMgr)
#define eObjectMgr              (sObjectMgr)
#define eAccountMgr             (sAccountMgr)
#define eAuctionMgr             (sAuctionMgr)
#define eObjectAccessor()       ObjectAccessor::
#define REGEN_TIME_FULL
typedef ThreatContainer::StorageType ThreatList;

#ifdef CATA
#define NUM_MSG_TYPES           NUM_OPCODE_HANDLERS
#endif
#endif

#ifndef TRINITY
#define eWorld                  (&sWorld)
#define eMapMgr                 (&sMapMgr)
#define eConfigMgr              (&sConfig)
#define eGuildMgr               (&sGuildMgr)
#define eObjectMgr              (&sObjectMgr)
#define eAccountMgr             (&sAccountMgr)
#define eAuctionMgr             (&sAuctionMgr)
#define eObjectAccessor()       sObjectAccessor.
#define SERVER_MSG_STRING       SERVER_MSG_CUSTOM
#define TOTAL_LOCALES           MAX_LOCALE
#define DIALOG_STATUS_SCRIPTED_NO_STATUS    DIALOG_STATUS_UNDEFINED
#define TARGETICONCOUNT         TARGET_ICON_COUNT
#define MAX_TALENT_SPECS        MAX_TALENT_SPEC_COUNT
#define TEAM_NEUTRAL            TEAM_INDEX_NEUTRAL

#ifndef CLASSIC
#define PLAYER_FIELD_LIFETIME_HONORABLE_KILLS   PLAYER_FIELD_LIFETIME_HONORBALE_KILLS
#endif

#ifdef TBC
#define SPELL_AURA_MOD_KILL_XP_PCT  SPELL_AURA_MOD_XP_PCT
#endif

#ifdef WOTLK
#define UNIT_BYTE2_FLAG_SANCTUARY   UNIT_BYTE2_FLAG_SUPPORTABLE
#endif

typedef TemporarySummon TempSummon;
typedef SpellEntry SpellInfo;
enum SelectAggroTarget
{
    SELECT_TARGET_RANDOM = 0,   // Just selects a random target
    SELECT_TARGET_TOPAGGRO,     // Selects targes from top aggro to bottom
    SELECT_TARGET_BOTTOMAGGRO,  // Selects targets from bottom aggro to top
    SELECT_TARGET_NEAREST,
    SELECT_TARGET_FARTHEST
};
#endif // TRINITY

#endif // _ELUNA_INCLUDES_H
