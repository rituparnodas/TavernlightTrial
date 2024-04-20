--[[Q2 - Fix or improve the implementation of the below method

function printSmallGuildNames(memberCount)

    -- this method is supposed to print names of all guilds that have less than memberCount max members

    local selectGuildQuery = "SELECT name FROM guilds WHERE max_members < %d;"
    local resultId = db.storeQuery(string.format(selectGuildQuery, memberCount))
    local guildName = result.getString("name")
    print(guildName)
end
]]

--================================================================================================================
--Ans
--================================================================================================================

function printSmallGuildNames(memberCount)

    -- this method is supposed to print names of all guilds that have less than memberCount max members
    
    local selectGuildQuery = "SELECT name FROM guilds WHERE max_members < %d;"
    local resultId = db.storeQuery(string.format(selectGuildQuery, memberCount))
    
    if resultId ~= false then --Fix 1: Added Extra Checking For Data Validation
        repeat -- Fix 2: Added repeat loop For Iteration
            local guildName = result.getString(resultId, "name") -- Fix 3: Here I Added resultId As A Parameter
            print(guildName .. " ")  -- Improve: Added Blank Space (" ") For Better Reading Names
            
        until result.next(resultId) ~= true
    end
end