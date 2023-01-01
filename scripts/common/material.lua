local mod = {
    loadOrder = 1
}

local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

function mod:onload(material)

    local function createDebug(key, color)
        mj:insertIndexed(material.types, {
            key = key,
            color = color,
            roughness = 1.1,
            metal = 1.1,
            colorB = vec3(0,0,0),
            roughnessB = 1.1 * 0.9,
            metalB = 1.1
        })
    end

    createDebug("debug_fjords", vec3(0, 0, 255))
    createDebug("debug_mesa", vec3(0, 255, 0))
    createDebug("debug_plains", vec3(0, 255, 255))
    createDebug("debug_swamp", vec3(255, 0, 0))
    createDebug("debug_desert_oasis", vec3(255, 0, 255))
    createDebug("debug_hillsides", vec3(255, 255, 0))
end

return mod