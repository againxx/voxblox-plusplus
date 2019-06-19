#include "global_segment_map/meshing/instance_color_map.h"

#include "voxblox/core/color.h"

namespace voxblox {

void InstanceColorMap::getColor(const InstanceLabel& instance_label,
                                Color* color) {
  CHECK_NOTNULL(color);

  auto instance_color_map_it = color_map_.find(instance_label);

  if (instance_color_map_it != color_map_.end()) {
    *color = instance_color_map_it->second;
  } else {
    if (instance_label == 0u) {
      // TODO(margaritaG): parametrize the grey color.
      color->r = 200u;
      color->g = 200u;
      color->b = 200u;
    } else {
      *color = randomColor();
    }

    color_map_.insert(std::pair<InstanceLabel, Color>(instance_label, *color));
  }
}
}  // namespace voxblox
