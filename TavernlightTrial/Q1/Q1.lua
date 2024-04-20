--[[
Q1 - Fix or improve the implementation of the below methods

 
local function releaseStorage(player)
    player:setStorageValue(1000, -1)
end

function onLogout(player)
        if player:getStorageValue(1000) == 1 then
        addEvent(releaseStorage, 1000, player)
        end
    return true
end
]]

--========================================================================================
--Ans:
--========================================================================================

_G.StorageID = 1000 -- Improve 1: For Storage ID I Made A Global Variable From A Hard-Coded Value (1000 Previous)

-- Improve 2 : For Storage ID I Made Another Parameter To Make This Function Flexible
local function releaseStorage(player, storageID)
    player:setStorageValue(storageID, -1)
end

function onLogout(player)
        if player:getStorageValue(StorageID) == 1 then -- Improve: Here I Replaced The Hard-Coded Value (1000) To The Global Variable StorageID
        addEvent(releaseStorage, 1000, player, StorageID) --Fix: Here I Added The Parameter Of The Function 'releaseStorage'
        end
    return true
end
