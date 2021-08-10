#pragma once
#include <cstdint>
#include "fwddec.hpp"
#include "extensible.hpp"
#include "vector.hpp"
#include "gta\natives.hpp"

#pragma pack(push, 1)
namespace rage
{
#	pragma warning(push)
#	pragma warning(disable : 4201) // nonstandard extension used: nameless struct/union
	union netAddress
	{
		std::uint32_t m_raw;
		struct
		{
			std::uint8_t m_field4;
			std::uint8_t m_field3;
			std::uint8_t m_field2;
			std::uint8_t m_field1;
		};
	};
#	pragma warning(pop)

	class netPlayerData
	{
	public:
		char pad_0000[16]; //0x0000
		uint32_t m_sec_key_time; //0x0010
		netAddress m_lan_ip; //0x0014
		uint16_t m_lan_port; //0x0018
		char pad_001A[2]; //0x001A
		netAddress m_relay_ip; //0x001C
		uint32_t m_relay_port; //0x0020
		netAddress m_online_ip; //0x0024
		uint16_t m_online_port; //0x0028
		char pad_002A[22]; //0x002A
		int32_t m_host_token; //0x0040
		char pad_0044[12]; //0x0044
		uint64_t m_rockstar_id; //0x0050
		char pad_0058[12]; //0x0058
		char m_name[20]; //0x0064
	}; //Size: 0x0078

	class nonPhysicalPlayerDataBase
	{
	public:
		virtual ~nonPhysicalPlayerDataBase() = default;    // 0 (0x00)
		virtual void unk_0x08() = 0;                       // 1 (0x08)
		virtual void unk_0x10() = 0;                       // 2 (0x10)
		virtual void unk_0x18() = 0;                       // 3 (0x18)
		virtual void log(netLoggingInterface* logger) = 0; // 4 (0x20)
	};

	class netPlayer
	{
	public:
		virtual ~netPlayer() = default;            // 0 (0x00)
		virtual void reset() = 0;                  // 1 (0x08)
		virtual bool is_valid() const = 0;         // 2 (0x10)
		virtual const char *get_name() const = 0;  // 3 (0x18)
		virtual void _0x20() = 0;                  // 4 (0x20)
		virtual bool is_host() = 0;                // 5 (0x28)
		virtual netPlayerData *get_net_data() = 0; // 6 (0x30)
		virtual void _0x38() = 0;                  // 7 (0x38)
	};

	class netPlayerMgrBase
	{
	public:
		virtual ~netPlayerMgrBase() = default; // 0 (0x00)
	};
}

namespace gta
{
	inline constexpr auto num_players = 32;
}

class CNonPhysicalPlayerData : public rage::nonPhysicalPlayerDataBase
{
public:
	std::int32_t  m_bubble_id; // 0x08
	std::int32_t  m_player_id; // 0x0C
	rage::vector3 m_position;  // 0x10
};

class CNetGamePlayer : public rage::netPlayer
{
public:
	char pad_0008[45]; //0x0008
	int8_t player_id; //0x0035
	char pad_0036[122]; //0x0036
	CPlayerInfo* player_info; //0x00B0
	char pad_00B8[20]; //0x00B8
	uint32_t bubble_id; //0x00CC
	uint32_t player; //0x00D0
};

class CPlayerInfo
{
public:
	char pad_0000[84]; //0x0000
	rage::netAddress m_internal_ip; //0x0054
	uint16_t m_internal_port; //0x0058
	char pad_005A[2]; //0x005A
	rage::netAddress m_relay_ip; //0x005C
	uint16_t m_relay_port; //0x0060
	char pad_0062[2]; //0x0062
	rage::netAddress m_external_ip; //0x0064
	uint16_t m_external_port; //0x0068
	char pad_006A[38]; //0x006A
	uint64_t m_rockstar_id; //0x0090
	char pad_0098[12]; //0x0098
	char m_name[20]; //0x00A4
	char pad_00B8[180]; //0x00B8
	float m_swim_speed; //0x016C
	float m_run_speed; //0x0170
	char pad_0174[81]; //0x0174
	bool m_is_rockstar_dev; //0x01C5
	char pad_01C6[1]; //0x01C6
	bool m_is_cheater; //0x01C7
	char pad_01C8[11]; //0x01C8
	bool m_is_online; //0x01D3
	char pad_01D4[20]; //0x01D4
	class rage::CPed* m_ped; //0x01E8
	char pad_01F0[40]; //0x01F0
	uint32_t m_frame_flags; //0x0218
	char pad_021C[28]; //0x021C
	uint32_t m_player_controls; //0x0238
	char pad_023C[1588]; //0x023C
	uint32_t m_npc_ignore; //0x0870
	char pad_0874[12]; //0x0874
	bool m_is_wanted; //0x0880
	char pad_0881[3]; //0x0881
	int8_t m_wanted_level_display; //0x0884
	char pad_0885[3]; //0x0885
	int8_t m_wanted_level; //0x0888
}; //Size: 0x0889
static_assert(sizeof(CPlayerInfo) == 0x0889, "CPlayerInfo is not properly sized");

class CNetworkIncrementStatEvent
{
public:
	char pad_0000[48]; //0x0000
	Hash m_hash; //0x0030
}; //Size: 0x0034

static_assert(sizeof(CNonPhysicalPlayerData) == 0x1C);
#pragma pack(pop)
