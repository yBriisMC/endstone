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
    struct StoredCustomItemDefinition {
        explicit StoredCustomItemDefinition(CustomItemDefinition definition);

        CustomItemDefinition definition;
        std::string base_type_storage;
    };

    struct StoredCustomBlockDefinition {
        explicit StoredCustomBlockDefinition(CustomBlockDefinition definition);

        CustomBlockDefinition definition;
        std::string base_type_storage;
    };

    std::unordered_map<std::string, StoredCustomItemDefinition> items_;
    std::unordered_map<std::string, StoredCustomBlockDefinition> blocks_;
    std::unordered_map<std::string, CustomEnchantmentDefinition> enchants_;
};
}  // namespace endstone::core
