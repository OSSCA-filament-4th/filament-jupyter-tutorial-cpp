#pragma once

#include "nlohmann/json.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xmaterialize.hpp"
#include "xwidgets/xtransport.hpp"

namespace nloh = nlohmann;

template <typename T>
class Canvas : public xw::xwidget<T> {

    using base_type = xw::xwidget<T>;
    using derived_type = T;

public:
    Canvas(): base_type() {
        this->_model_module() = "ipycanvas";
        this->_view_module() = "ipycanvas";
        this->_model_name() = "CanvasModel";
        this->_view_name() = "CanvasView";
        // this->_model_module_version() = jupyter_canvas_semver();
        // this->_view_module_version() = jupyter_canvas_semver();
    }

public:
    XPROPERTY(bool, derived_type, _send_client_ready_event, false);
    XPROPERTY(int, derived_type, width, 700);
    XPROPERTY(int, derived_type, height, 500);


    // only needed functions
    void serialize_state(nloh::json& state, xeus::buffer_sequence& buffers) const {

        base_type::serialize_state(state, buffers);

        // widget serilziation
        xw::xwidgets_serialize(_send_client_ready_event(), state["_send_client_ready_event"], buffers);
        xw::xwidgets_serialize(width(), state["width"], buffers);
        xw::xwidgets_serialize(height(), state["height"], buffers);
    }

    void apply_patch(const nl::json& patch, const xeus::buffer_sequence& buffers) {
        base_type::apply_patch(patch, buffers);
    
        using xw::set_property_from_patch;

        set_property_from_patch(width, patch, buffers);
        set_property_from_patch(height, patch, buffers);
    }

    // void notify(const std::string& name, const T& value) {
    //     base_type::notify(name, value);
    // }

    // nloh::json get_context {
    //     send_command(
    //         nloh::json::array(
    //             { }
    //         )
    //     );
    // }

private:
    nloh::json m_commands;
};

using xx = xw::xmaterialize<Canvas>;

extern template class xw::xmaterialize<Canvas>;
extern template class xw::xtransport<xw::xmaterialize<Canvas>>;