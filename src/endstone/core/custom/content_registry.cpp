#include "endstone/core/custom/content_registry.h"

namespace endstone::core {

EndstoneContentRegistry::StoredCustomItemDefinition::StoredCustomItemDefinition(CustomItemDefinition definition)
    : definition(std::move(definition)), base_type_storage(static_cast<std::string>(this->definition.base_type))
{
    this->definition.base_type = ItemTypeId(base_type_storage);
}

EndstoneContentRegistry::StoredCustomBlockDefinition::StoredCustomBlockDefinition(CustomBlockDefinition definition)
    : definition(std::move(definition)), base_type_storage(static_cast<std::string>(this->definition.base_type))
{
    this->definition.base_type = BlockTypeId(base_type_storage);
}

bool EndstoneContentRegistry::registerCustomItem(ItemTypeId id, CustomItemDefinition definition)
{
    return items_.emplace(std::string(id), StoredCustomItemDefinition(std::move(definition))).second;
}

bool EndstoneContentRegistry::registerCustomBlock(BlockTypeId id, CustomBlockDefinition definition)
{
    return blocks_.emplace(std::string(id), StoredCustomBlockDefinition(std::move(definition))).second;
}

bool EndstoneContentRegistry::registerCustomEnchantment(EnchantmentId id, CustomEnchantmentDefinition definition)
{
    return enchants_.emplace(std::string(id), std::move(definition)).second;
}

const CustomItemDefinition *EndstoneContentRegistry::getCustomItem(ItemTypeId id) const
{
    auto it = items_.find(std::string(id));
    return it == items_.end() ? nullptr : &it->second.definition;
}

const CustomBlockDefinition *EndstoneContentRegistry::getCustomBlock(BlockTypeId id) const
{
    auto it = blocks_.find(std::string(id));
    return it == blocks_.end() ? nullptr : &it->second.definition;
}

const CustomEnchantmentDefinition *EndstoneContentRegistry::getCustomEnchantment(EnchantmentId id) const
{
    auto it = enchants_.find(std::string(id));
    return it == enchants_.end() ? nullptr : &it->second;
}

ActorTypeId EndstoneContentRegistry::getHumanActorType() const
{
    return ActorTypeId::minecraft("player");
}

}  // namespace endstone::core
