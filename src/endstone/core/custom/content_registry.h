#pragma once

#include "endstone/custom/content_registry.h"

namespace endstone::core {
class EndstoneContentRegistry final : public ContentRegistry {
public:
    bool registerCustomItem(ItemTypeId id, CustomItemDefinition definition) override;
    bool registerCustomBlock(BlockTypeId id, CustomBlockDefinition definition) override;
    bool registerCustomEnchantment(EnchantmentId id, CustomEnchantmentDefinition definition) override;

    [[nodiscard]] const CustomItemDefinition *getCustomItem(ItemTypeId id) const override;
    [[nodiscard]] const CustomBlockDefinition *getCustomBlock(BlockTypeId id) const override;
    [[nodiscard]] const CustomEnchantmentDefinition *getCustomEnchantment(EnchantmentId id) const override;

    [[nodiscard]] ActorTypeId getHumanActorType() const override;

private:
    std::unordered_map<std::string, CustomItemDefinition> items_;
    std::unordered_map<std::string, CustomBlockDefinition> blocks_;
    std::unordered_map<std::string, CustomEnchantmentDefinition> enchants_;
};
}  // namespace endstone::core
