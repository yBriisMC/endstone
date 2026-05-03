#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "endstone/actor/actor_type.h"
#include "endstone/block/block_type.h"
#include "endstone/enchantments/enchantment.h"
#include "endstone/inventory/item_type.h"

namespace endstone {

struct CustomItemDefinition {
    ItemTypeId base_type{ItemType::Air};
    std::string display_name;
};

struct CustomBlockDefinition {
    BlockTypeId base_type{BlockType::Air};
    std::string display_name;
};

struct CustomEnchantmentDefinition {
    std::string translation_key;
    int start_level{1};
    int max_level{1};
};

class ContentRegistry {
public:
    virtual ~ContentRegistry() = default;

    virtual bool registerCustomItem(ItemTypeId id, CustomItemDefinition definition) = 0;
    virtual bool registerCustomBlock(BlockTypeId id, CustomBlockDefinition definition) = 0;
    virtual bool registerCustomEnchantment(EnchantmentId id, CustomEnchantmentDefinition definition) = 0;

    [[nodiscard]] virtual const CustomItemDefinition *getCustomItem(ItemTypeId id) const = 0;
    [[nodiscard]] virtual const CustomBlockDefinition *getCustomBlock(BlockTypeId id) const = 0;
    [[nodiscard]] virtual const CustomEnchantmentDefinition *getCustomEnchantment(EnchantmentId id) const = 0;

    [[nodiscard]] virtual ActorTypeId getHumanActorType() const = 0;
};

}  // namespace endstone
