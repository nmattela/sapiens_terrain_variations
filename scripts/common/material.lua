local mod = {
    loadOrder = 1
}

local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

function mod:onload(material)

    -- local function createDebug(key, color)
    --     mj:insertIndexed(material.types, {
    --         key = key,
    --         color = color,
    --         roughness = 1.1,
    --         metal = 0.1,
    --         colorB = vec3(0,0,0),
    --         roughnessB = 1.1 * 0.9,
    --         metalB = 0.1
    --     })
    -- end

    -- -- for r = 0, 255, 1 do
    -- --     for g = 0, 255, 1 do
    -- --         for b = 0, 255, 1 do
    -- --             createDebug("debug_"..r.."_"..g.."_"..b, vec3(r/255, g/255, b/255))
    -- --         end
    -- --     end
    -- -- end

    -- for i = 0, 255, 1 do
    --     createDebug("debug_"..i.."_0_0", vec3(i/255, 0, 0))
    --     createDebug("debug_0_"..i.."_0", vec3(0, i/255, 0))
    --     createDebug("debug_0_0_"..i    , vec3(0, 0, i/255))
    -- end
end

return mod