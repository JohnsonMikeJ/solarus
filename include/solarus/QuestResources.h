/*
 * Copyright (C) 2006-2014 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_QUEST_RESOURCE_H
#define SOLARUS_QUEST_RESOURCE_H

#include "solarus/Common.h"
#include "solarus/ResourceType.h"
#include <map>
#include <string>

namespace Solarus {

/**
 * \brief Stores the resource list of a quest.
 */
class QuestResources {

  public:

    QuestResources();

    void clear();

    bool load_from_buffer(const std::string& buffer);
    bool load_from_file(const std::string& file_name);

    bool exists(ResourceType resource_type, const std::string& id) const;
    const std::map<std::string, std::string>& get_elements(
        ResourceType resource_type
    ) const;

    void add(
        ResourceType resource_type,
        const std::string& id,
        const std::string& description
    );

    static const std::string& get_resource_type_name(ResourceType resource_type);
    static ResourceType get_resource_type_by_name(const std::string& resource_type_name);

  private:

    using ResourceMap = std::map<std::string, std::string>;

    std::map<ResourceType, ResourceMap> resource_maps;

};

}

#endif
