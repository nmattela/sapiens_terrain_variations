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

    createDebug("debug_fjords")
    createDebug("debug_mesa")
    createDebug("debug_plains")
    createDebug("debug_swamp")
    createDebug("debug_desert_oasis")
    createDebug("debug_hillsides")
end

return mod