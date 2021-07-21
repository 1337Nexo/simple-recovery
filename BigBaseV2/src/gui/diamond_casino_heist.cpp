#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "diamond_casino_heist.h"
#include "gta\joaat.hpp"
#include "local_player.hpp"
#include "fiber_pool.hpp"

using namespace big;

namespace big
{
	static class diamondheistinfo
	{
	public:
		static inline int approach{}, target{}, last_approach{}, hard_approach{};
		static inline int disrupt{}, keylevels{}, crewweap{}, crewdriver{}, crewhacker{}, vehs{}, weaps{}, masks{}, bodyarmorlvl{}, bitset{}, bitsetone{};
	} diamond_heist_info;

	enum CasinoHeistBitsetZero : uint32_t
	{
		PatrolRoutes = 0x00000002,
		DugganShipments = 0x00000004,
		InfiltrationSuits = 0x00000008,
		PowerDrills = 0x00000010,
		EMP = 0x00000020,
		GunmanDecoy = 0x00000040,
		CleanVehicle = 0x00000080,
		BugstarsPartOne = 0x00000100,
		BugstarsPartTwo = 0x00000200,
		MaintenancePartOne = 0x00000400,
		MaintenancePartTwo = 0x00000800,
		GruppeSechsPartOne = 0x00001000,
		GruppeSechsPartTwo = 0x00002000,
		YungAncestorPartOne = 0x00004000,
		YungAncestorPartTwo = 0x00008000,
		NOOSEGearExitDisguise = 0x00010000,
		FirefighterGearExitDisguise = 0x00020000,
		HighRollerExitDisguise = 0x00040000,
		ReinforcedArmor = 0x00100000,
		BoringMachine = 0x00280000
	};

	enum CasinoHeistBitsetOne : uint32_t
	{
		VaultContents = 0x00000001,
		VaultKeys = 0x00000002,
		WeaponsMissionFinished = 0x00000004,
		VehicleMissionFinished = 0x00000008,
		HackingDevice = 0x00000010,
		NanoDrone = 0x00000020,
		VaultLaser = 0x00000040,
		VaultDrill = 0x00000080,
		VaultExplosives = 0x00000100,
		ThermalCharges = 0x00000200
	};

	void diamond_casino_heist::do_presentation_layer()
	{
		bool is_mp0_char = g_local_player.character_index == 1 ? false : true;

		const char* const approach_list[] = { "Unselected", "Silent & Sneaky", "The Big Con", "Aggressive" };
		ImGui::PushItemWidth(160);
		if (ImGui::Combo("Select Approach", &diamond_heist_info.approach, approach_list, IM_ARRAYSIZE(approach_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_APPROACH") : RAGE_JOAAT("MP1_H3OPT_APPROACH"), diamond_heist_info.approach);
		const char* const target_list[] = { "Money", "Gold", "Art", "Diamonds" };
		ImGui::PopItemWidth();
		ImGui::PushItemWidth(160);
		if (ImGui::Combo("Select Target", &diamond_heist_info.target, target_list, IM_ARRAYSIZE(target_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_TARGET") : RAGE_JOAAT("MP1_H3OPT_TARGET"), diamond_heist_info.target);
		ImGui::PopItemWidth();
		ImGui::SameLine();
		bool vault_contents = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::VaultContents);
		if (ImGui::Checkbox("Vault Contents", &vault_contents))
			set_bitset_one(CasinoHeistBitsetOne::VaultContents);

		ImGui::PushItemWidth(160);
		if (ImGui::Combo("Last Heist", &diamond_heist_info.last_approach, approach_list, IM_ARRAYSIZE(approach_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3_LAST_APPROACH") : RAGE_JOAAT("MP1_H3_LAST_APPROACH"), diamond_heist_info.last_approach);
		ImGui::SameLine();
		if (ImGui::Combo("Hard Approach", &diamond_heist_info.hard_approach, approach_list, IM_ARRAYSIZE(approach_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3_HARD_APPROACH") : RAGE_JOAAT("MP1_H3_HARD_APPROACH"), diamond_heist_info.hard_approach);
		ImGui::PopItemWidth();

		ImGui::Separator();

		const char* const gunman_list[] = { "Unselected", "Karl Abolaji", "Gustavo Mota", "Charlie Reed", "Chester McCoy", "Patrick McReary" };
		ImGui::PushItemWidth(175);
		if (ImGui::Combo("Gunman", &diamond_heist_info.crewweap, gunman_list, IM_ARRAYSIZE(gunman_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_CREWWEAP") : RAGE_JOAAT("MP1_H3OPT_CREWWEAP"), diamond_heist_info.crewweap);
		ImGui::SameLine();
		const char* const driver_list[] = { "Unselected", "Karim Deniz", "Taliana Martinez", "Eddie Toh", "Zach Nelson", "Chester McCoy" };
		if (ImGui::Combo("Driver", &diamond_heist_info.crewdriver, driver_list, IM_ARRAYSIZE(driver_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_CREWDRIVER") : RAGE_JOAAT("MP1_H3OPT_CREWDRIVER"), diamond_heist_info.crewdriver);
		ImGui::SameLine();
		const char* const hacker_list[] = { "Unselected", "Rickie Lukens", "Christian Feltz", "Yohan Blair", "Avi Schwartzman", "Page Harris" };
		if (ImGui::Combo("Hacker", &diamond_heist_info.crewhacker, hacker_list, IM_ARRAYSIZE(hacker_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_CREWHACKER") : RAGE_JOAAT("MP1_H3OPT_CREWHACKER"), diamond_heist_info.crewhacker);
		ImGui::PopItemWidth();
		switch (diamond_heist_info.crewweap)
		{
		case 1: //Karl Abolaji
		{
			const char* const karl_gun_list[4][2] = { {"##1", "##2"}, { "Micro SMG Loadout", "Machine Pistol Loadout" }, { "Micro SMG Loadout", "Shotgun Loadout" }, { "Shotgun Loadout", "Revolver Loadout" } };
			ImGui::PushItemWidth(230);
			if (ImGui::Combo("Unmarked Weapons##2", &diamond_heist_info.weaps, karl_gun_list[diamond_heist_info.approach], 2))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_WEAPS") : RAGE_JOAAT("MP1_H3OPT_WEAPS"), diamond_heist_info.weaps);
			ImGui::SameLine();
			ImGui::PopItemWidth();
			break;
		}
		case 2: //Gustavo Mota
		{
			const char* const gus_gun_list[] = { "Rifle Loadout", "Shotgun Loadout" };
			ImGui::PushItemWidth(190);
			if (ImGui::Combo("Unmarked Weapons##2", &diamond_heist_info.weaps, gus_gun_list, IM_ARRAYSIZE(gus_gun_list)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_WEAPS") : RAGE_JOAAT("MP1_H3OPT_WEAPS"), diamond_heist_info.weaps);
			ImGui::SameLine();
			ImGui::PopItemWidth();
			break;
		}
		case 3: //Charlie Reed
		{
			const char* const charlie_gun_list[4][2] = { {"##1", "##2"}, { "SMG Loadout", "Shotgun Loadout" }, { "Machine Pistol Loadout", "Shotgun Loadout" }, { "SMG Loadout", "Shotgun Loadout" } };
			ImGui::PushItemWidth(230);
			if (ImGui::Combo("Unmarked Weapons##2", &diamond_heist_info.weaps, charlie_gun_list[diamond_heist_info.approach], 2))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_WEAPS") : RAGE_JOAAT("MP1_H3OPT_WEAPS"), diamond_heist_info.weaps);
			ImGui::SameLine();
			ImGui::PopItemWidth();
			break;
		}
		case 4: //Chester McCoy
		{
			const char* const chester_gun_list[4][2] = { {"##1", "##2"}, { "MK II Shotgun Loadout", "MK II Rifle Loadout" }, { "MK II SMG Loadout", "MK II Rifle Loadout" }, { "MK II Shotgun Loadout", "MK II Rifle Loadout" } };
			ImGui::PushItemWidth(230);
			if (ImGui::Combo("Unmarked Weapons##2", &diamond_heist_info.weaps, chester_gun_list[diamond_heist_info.approach], 2))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_WEAPS") : RAGE_JOAAT("MP1_H3OPT_WEAPS"), diamond_heist_info.weaps);
			ImGui::SameLine();
			ImGui::PopItemWidth();
			break;
		}
		case 5: //Patrick McReary
		{
			const char* const packie_gun_list[4][2] = { {"##1", "##2"}, { "Combat PDW Loadout", "Rifle Loadout" }, { "Shotgun Loadout", "Rifle Loadout" }, { "Shotgun Loadout", "Combat MG Loadout" } };
			ImGui::PushItemWidth(230);
			if (ImGui::Combo("Unmarked Weapons##2", &diamond_heist_info.weaps, packie_gun_list[diamond_heist_info.approach], 2))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_WEAPS") : RAGE_JOAAT("MP1_H3OPT_WEAPS"), diamond_heist_info.weaps);
			ImGui::SameLine();
			ImGui::PopItemWidth();
		}
		}

		switch (diamond_heist_info.crewdriver)
		{
		case 1: //Karim Deniz
		{
			const char* const karim_vehicle_list[] = { "Issi Classic", "Asbo", "Kanjo", "Sentinel Classic" };
			ImGui::PushItemWidth(170);
			if (ImGui::Combo("Getaway Vehicles##2", &diamond_heist_info.vehs, karim_vehicle_list, IM_ARRAYSIZE(karim_vehicle_list)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_VEHS") : RAGE_JOAAT("MP1_H3OPT_VEHS"), diamond_heist_info.vehs);
			ImGui::PopItemWidth();
			break;
		}
		case 2: //Taliana Martinez
		{
			const char* const taliana_vehicle_list[] = { "Retinue MK II", "Drift Yosemite", "Sugoi", "Jugular" };
			if (ImGui::Combo("Getaway Vehicles##2", &diamond_heist_info.vehs, taliana_vehicle_list, IM_ARRAYSIZE(taliana_vehicle_list)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_VEHS") : RAGE_JOAAT("MP1_H3OPT_VEHS"), diamond_heist_info.vehs);
			break;
		}
		case 3: //Eddie Toh
		{
			const char* const eddie_vehicle_list[] = { "Sultan Classic", "Guantlet Classic", "Ellie", "Komoda" };
			ImGui::PushItemWidth(170);
			if (ImGui::Combo("Getaway Vehicles##2", &diamond_heist_info.vehs, eddie_vehicle_list, IM_ARRAYSIZE(eddie_vehicle_list)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_VEHS") : RAGE_JOAAT("MP1_H3OPT_VEHS"), diamond_heist_info.vehs);
			ImGui::PopItemWidth();
			break;
		}
		case 4: //Zach Nelson
		{
			const char* const zach_vehicle_list[] = { "Manchez", "Stryder", "Defiler", "Lectro" };
			if (ImGui::Combo("Getaway Vehicles##2", &diamond_heist_info.vehs, zach_vehicle_list, IM_ARRAYSIZE(zach_vehicle_list)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_VEHS") : RAGE_JOAAT("MP1_H3OPT_VEHS"), diamond_heist_info.vehs);
			break;
		}
		case 5: //Chester McCoy
		{
			const char* const chester_vehicle_list[] = { "Zhaba", "Vagrant", "Outlaw", "Everon" };
			if (ImGui::Combo("Getaway Vehicles##2", &diamond_heist_info.vehs, chester_vehicle_list, IM_ARRAYSIZE(chester_vehicle_list)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_VEHS") : RAGE_JOAAT("MP1_H3OPT_VEHS"), diamond_heist_info.vehs);
			break;
		}
		}

		bool weapons_mission = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::WeaponsMissionFinished);
		if (ImGui::Checkbox("Unmarked Weapons##1", &weapons_mission))
			set_bitset_one(CasinoHeistBitsetOne::WeaponsMissionFinished);
		bool patrol_routes = (diamond_heist_info.bitset & CasinoHeistBitsetZero::PatrolRoutes);
		if (ImGui::Checkbox("Patrol Routes", &patrol_routes))
			set_bitset(CasinoHeistBitsetZero::PatrolRoutes);

		bool vehicle_mission = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::VehicleMissionFinished);
		if (ImGui::Checkbox("Getaway Vehicles##1", &vehicle_mission))
			set_bitset_one(CasinoHeistBitsetOne::VehicleMissionFinished);
		bool duggan_shipments = (diamond_heist_info.bitset & CasinoHeistBitsetZero::DugganShipments);
		if (ImGui::Checkbox("Duggan Shipments", &duggan_shipments))
			set_bitset(CasinoHeistBitsetZero::DugganShipments);

		bool hacking_device = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::HackingDevice);
		if (ImGui::Checkbox("Hacking Device", &hacking_device))
			set_bitset_one(CasinoHeistBitsetOne::HackingDevice);

		bool vault_keys = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::VaultKeys);
		if (ImGui::Checkbox("Vault Keycards", &vault_keys))
			set_bitset_one(CasinoHeistBitsetOne::VaultKeys);
		bool power_drills = (diamond_heist_info.bitset & CasinoHeistBitsetZero::PowerDrills);
		if (ImGui::Checkbox("Power Drills", &power_drills))
			set_bitset(CasinoHeistBitsetZero::PowerDrills);

		if (diamond_heist_info.approach == 1)
		{
			bool nano_drone = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::NanoDrone);
			if (ImGui::Checkbox("Nano Drone", &nano_drone))
				set_bitset_one(CasinoHeistBitsetOne::NanoDrone);
			ImGui::SameLine();
			bool steal_emp = (diamond_heist_info.bitset & CasinoHeistBitsetZero::EMP);
			if (ImGui::Checkbox("Steal EMP", &steal_emp))
				set_bitset(CasinoHeistBitsetZero::EMP);

			bool vault_laser = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::VaultLaser);
			if (ImGui::Checkbox("Vault Laser", &vault_laser))
				set_bitset_one(CasinoHeistBitsetOne::VaultLaser);
			ImGui::SameLine();
			bool infiltration_suits = (diamond_heist_info.bitset & CasinoHeistBitsetZero::InfiltrationSuits);
			if (ImGui::Checkbox("Infiltration Suits", &infiltration_suits))
				set_bitset(CasinoHeistBitsetZero::InfiltrationSuits);
		}
		else if (diamond_heist_info.approach == 2)
		{
			bool bugstars_part_one = (diamond_heist_info.bitset & CasinoHeistBitsetZero::BugstarsPartOne);
			if (ImGui::Checkbox("Bugstars I", &bugstars_part_one))
				set_bitset(CasinoHeistBitsetZero::BugstarsPartOne);
			ImGui::SameLine();
			bool bugstars_part_two = (diamond_heist_info.bitset & CasinoHeistBitsetZero::BugstarsPartTwo);
			if (ImGui::Checkbox("II##bug", &bugstars_part_two))
				set_bitset(CasinoHeistBitsetZero::BugstarsPartTwo);
			ImGui::SameLine();
			bool maintenance_part_one = (diamond_heist_info.bitset & CasinoHeistBitsetZero::MaintenancePartOne);
			if (ImGui::Checkbox("Maintenance I", &maintenance_part_one))
				set_bitset(CasinoHeistBitsetZero::MaintenancePartOne);
			ImGui::SameLine();
			bool maintenance_part_two = (diamond_heist_info.bitset & CasinoHeistBitsetZero::MaintenancePartTwo);
			if (ImGui::Checkbox("II##maint", &maintenance_part_two))
				set_bitset(CasinoHeistBitsetZero::MaintenancePartTwo);

			bool gruppe_sechs_part_one = (diamond_heist_info.bitset & CasinoHeistBitsetZero::GruppeSechsPartOne);
			if (ImGui::Checkbox("Gruppe Sechs I", &gruppe_sechs_part_one))
				set_bitset(CasinoHeistBitsetZero::GruppeSechsPartOne);
			ImGui::SameLine();
			bool gruppe_sechs_part_two = (diamond_heist_info.bitset & CasinoHeistBitsetZero::GruppeSechsPartTwo);
			if (ImGui::Checkbox("II##gruppe", &gruppe_sechs_part_two))
				set_bitset(CasinoHeistBitsetZero::GruppeSechsPartTwo);
			ImGui::SameLine();
			bool yung_ancestor_part_one = (diamond_heist_info.bitset & CasinoHeistBitsetZero::YungAncestorPartOne);
			if (ImGui::Checkbox("Yung Ancestor I", &yung_ancestor_part_one))
				set_bitset(CasinoHeistBitsetZero::YungAncestorPartOne);
			ImGui::SameLine();
			bool yung_ancestor_part_two = (diamond_heist_info.bitset & CasinoHeistBitsetZero::YungAncestorPartTwo);
			if (ImGui::Checkbox("II##yung", &yung_ancestor_part_two))
				set_bitset(CasinoHeistBitsetZero::YungAncestorPartTwo);

			bool vault_drills = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::VaultDrill);
			if (ImGui::Checkbox("Vault Drills", &vault_drills))
				set_bitset_one(CasinoHeistBitsetOne::VaultDrill);
			ImGui::SameLine();
			bool noose_exit = (diamond_heist_info.bitset & CasinoHeistBitsetZero::NOOSEGearExitDisguise);
			if (ImGui::Checkbox("NOOSE Exit", &noose_exit))
				set_bitset(CasinoHeistBitsetZero::NOOSEGearExitDisguise);
			ImGui::SameLine();
			bool firefighter_exit = (diamond_heist_info.bitset & CasinoHeistBitsetZero::FirefighterGearExitDisguise);
			if (ImGui::Checkbox("Firefighters Exit", &firefighter_exit))
				set_bitset(CasinoHeistBitsetZero::FirefighterGearExitDisguise);
			ImGui::SameLine();
			bool highroller_exit = (diamond_heist_info.bitset & CasinoHeistBitsetZero::HighRollerExitDisguise);
			if (ImGui::Checkbox("High Rollers Exit", &highroller_exit))
				set_bitset(CasinoHeistBitsetZero::HighRollerExitDisguise);
		}
		else if (diamond_heist_info.approach == 3)
		{
			bool thermal_charges = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::ThermalCharges);
			if (ImGui::Checkbox("Thermal Charges", &thermal_charges))
				set_bitset_one(CasinoHeistBitsetOne::ThermalCharges);
			ImGui::SameLine();
			bool reinforced_armor = (diamond_heist_info.bitset & CasinoHeistBitsetZero::ReinforcedArmor);
			if (ImGui::Checkbox("Reinforced Armor", &reinforced_armor))
				set_bitset(CasinoHeistBitsetZero::ReinforcedArmor);
			ImGui::SameLine();
			ImGui::PushItemWidth(185);
			const char* const armor_levels[] = { "Unselected", "One", "Two", "Three" };
			if (ImGui::Combo("Armor Level", &diamond_heist_info.bodyarmorlvl, armor_levels, IM_ARRAYSIZE(armor_levels)))
				set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_BODYARMORLVL") : RAGE_JOAAT("MP1_H3OPT_BODYARMORLVL"), diamond_heist_info.bodyarmorlvl);
			ImGui::PopItemWidth();
			bool vault_explosives = (diamond_heist_info.bitsetone & CasinoHeistBitsetOne::VaultExplosives);
			if (ImGui::Checkbox("Vault Explosives", &vault_explosives))
				set_bitset_one(CasinoHeistBitsetOne::VaultExplosives);
			ImGui::SameLine();
			bool boring_machine = (diamond_heist_info.bitset & CasinoHeistBitsetZero::BoringMachine);
			if (ImGui::Checkbox("Boring Machine", &boring_machine))
				set_bitset(CasinoHeistBitsetZero::BoringMachine);
		}

		const char* const mask_list[] = { "Unselected", "Geometric Set", "Hunter Set", "Oni Half Mask Set", "Emoji Set", "Ornate Skull Set", "Lucky Fruit Set", "Gurilla Set", "Clown Set", "Animal Set", "Riot Set", "Oni Set", "Hockey Set" };
		ImGui::PushItemWidth(185);
		if (ImGui::Combo("Masks", &diamond_heist_info.masks, mask_list, IM_ARRAYSIZE(mask_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_MASKS") : RAGE_JOAAT("MP1_H3OPT_MASKS"), diamond_heist_info.masks);
		const char* const security_pass_list[] = { "Unselected", "Level 1", "Level 2" };
		if (ImGui::Combo("Security Pass", &diamond_heist_info.keylevels, security_pass_list, IM_ARRAYSIZE(security_pass_list)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_KEYLEVELS") : RAGE_JOAAT("MP1_H3OPT_KEYLEVELS"), diamond_heist_info.keylevels);
		const char* const disrupt_levels[] = { "Unselected", "One", "Two", "Three" };
		if (ImGui::Combo("Disrupt Level", &diamond_heist_info.disrupt, disrupt_levels, IM_ARRAYSIZE(disrupt_levels)))
			set_stat(is_mp0_char ? RAGE_JOAAT("MP0_H3OPT_DISRUPTSHIP") : RAGE_JOAAT("MP1_H3OPT_DISRUPTSHIP"), diamond_heist_info.disrupt);
		ImGui::PopItemWidth();

		bool clean_vehicle = (diamond_heist_info.bitset & CasinoHeistBitsetZero::CleanVehicle);
		if (ImGui::Checkbox("Clean Vehicle", &clean_vehicle))
			set_bitset(CasinoHeistBitsetZero::CleanVehicle);
		ImGui::SameLine();
		bool gunman_decoy = (diamond_heist_info.bitset & CasinoHeistBitsetZero::GunmanDecoy);
		if (ImGui::Checkbox("Gunman Decoy", &gunman_decoy))
			set_bitset(CasinoHeistBitsetZero::GunmanDecoy);
	}

	void set_stat(Hash stat, int value)
	{
		g_fiber_pool->queue_job([stat, value]
			{
				STATS::STAT_SET_INT(stat, value, TRUE);
			});
	}

	void set_bitset(int value)
	{
		diamond_heist_info.bitset ^= value;
		g_fiber_pool->queue_job([value]
			{
				auto stat = RAGE_JOAAT("MP0_H3OPT_BITSET0");
				STATS::STAT_SET_INT(stat, diamond_heist_info.bitset, TRUE);
			});
	}

	void set_bitset_one(int value)
	{
		diamond_heist_info.bitsetone ^= value;
		g_fiber_pool->queue_job([value]
			{
				auto stat = RAGE_JOAAT("MP0_H3OPT_BITSET1");
				STATS::STAT_SET_INT(stat, diamond_heist_info.bitsetone, TRUE);
			});
	}
}