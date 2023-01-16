local mod = {
    loadOrder = 1
}

local typeMaps = mjrequire "common/typeMaps"
local material = mjrequire "common/material"
local terrainDecal = mjrequire "common/terrainDecal"
local pathFinding = mjrequire "common/pathFinding"

local function createStandardOutputs(objectKeyName, countOrNil)
	local result = {}
	local count = countOrNil or 1
	for i=1,count do
		table.insert(result, {
			objectKeyName = objectKeyName,
			allowsOutputWhenVertexHasBeenFilled = true
		})
	end
	return result
end

function mod:onload(terrainTypes)

    local function createDebug(key)
        terrainTypes:addBaseType(key, {
            name = key,
            material = material.types[key].index,
            decalGroupTypeIndex = terrainDecal.groupTypes.dirtGrass.index,
            digOutputs = createStandardOutputs(key),
            fillObjectTypeKey = key,
            pathDifficultyIndex = pathFinding.pathNodeDifficulties.dirtRock.index,
            requiresMining = true,
            disableSpawn = false,
        })
    
        terrainTypes:addVariation(key, {
            name = key
        })
    end

    -- for r = 0, 255, 1 do
    --     for g = 0, 255, 1 do
    --         for b = 0, 255, 1 do
    --             createDebug("debug_"..r.."_"..g.."_")
    --         end
    --     end
    -- end

    for i = 0, 255, 1 do
        createDebug("debug_"..i.."_0_0")
        createDebug("debug_0_"..i.."_0")
        createDebug("debug_0_0_"..i)
    end
end

return mod