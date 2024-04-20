--[[Q3 - Fix or improve the name and the implementation of the below method

function do_sth_with_PlayerParty(playerId, membername)

    player = Player(playerId)

    local party = player:getParty()

    for k,v in pairs(party:getMembers()) do

        if v == Player(membername) then

            party:removeMember(Player(membername))
        end
    end
end
 ]]

 --=================================================================
 -- Answer
 --=================================================================

 --Improve: The Function Is Seems Like Removing A Member From A Player's Lobby So I Named It As 'RemoveMemberFromPlayerParty' Instead 'do_sth_with_PlayerParty'
function RemoveMemberFromPlayerParty(playerId, membername)

    player = Player(playerId)
    local party = player:getParty()

    for k, member in pairs(party:getMembers()) do
        if member:getName() == membername then -- Fix 1: A member From Party Is Also A Player So Assuming 'member:getName()' To Get The Name Of That Player And Otherside Of '==' It Shouldbe'membername' Not 'Player(membername)'
            party:removeMember(membername) -- Fix 2: It Should Be 'membername' Not 'Player(membername)''
        end
    end
end