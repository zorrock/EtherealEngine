#include "material.hpp"
#include "core/serialization/associative_archive.h"

REFLECT(material)
{
	rttr::registration::enumeration<cull_type>("cull_type")(
		rttr::value("none", cull_type::none), rttr::value("clockwise", cull_type::clockwise),
		rttr::value("counter_clockwise", cull_type::counter_clockwise));

	rttr::registration::class_<material>("material")
		.property("cull_type", &material::get_cull_type,
				  &material::set_cull_type)(rttr::metadata("pretty_name", "Cull Type"));
}

SAVE(material)
{
	try_save(ar, cereal::make_nvp("cull_type", obj._cull_type));
}
SAVE_INSTANTIATE(material, cereal::oarchive_associative_t);

LOAD(material)
{
	try_load(ar, cereal::make_nvp("cull_type", obj._cull_type));
}
LOAD_INSTANTIATE(material, cereal::iarchive_associative_t);
