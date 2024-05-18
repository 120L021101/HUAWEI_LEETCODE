local codewars = {}

local function checkIfLegal(i, j, spiral, move_f)
    n_i, n_j = move_f(i, j)
    if n_i == 1 or n_i == #spiral or n_j == 1 or 
       n_j == #spiral[1] or spiral[n_i][n_j] == 0 then
        return false
    end
    n_i, n_j = move_f(n_i, n_j)
    return spiral[n_i][n_j] ~= 0
end

local function up(i, j)
    return i - 1, j
end
local function down(i, j)
    return i + 1, j
end
local function left(i, j)
    return i, j - 1
end
local function right(i, j)
    return i, j + 1
end


function codewars.spiralize(size)
    local spiral = {}
    local directions_f = {right, down, left, up}
    local direction_idx = 1

    -- initialize
    for j = 1, size do
        spiral[j] = {}
        for k = 1, size do
            spiral[j][k] = 1
        end
    end

    -- start position
    local i = 2
    local j = 1
    spiral[i][j] = 0
    while true do
        local direction_f = directions_f[direction_idx]
        local n_i, n_j = direction_f(i, j)
        spiral[n_i][n_j] = 0
        if checkIfLegal(n_i, n_j, spiral, direction_f) == false then
            direction_idx = direction_idx + 1
            if direction_idx == #directions_f + 1 then
                direction_idx = 1
            end
            local next_direct_f = directions_f[direction_idx]
            if checkIfLegal(n_i, n_j, spiral, next_direct_f) == false then
                break
            end
            direction_f = next_direct_f
        end
        i, j = n_i, n_j
    end

    return spiral
end

return codewars