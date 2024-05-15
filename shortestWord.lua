local function find_short(s)
    -- Implement me! :D
    local min_length = string.len(s)
    local last_idx = 1
    local this_idx = 1
    while this_idx <= string.len(s) do
        if string.sub(s, this_idx, this_idx) ~= " " then
            this_idx = this_idx + 1
        else
            local current_length = this_idx - last_idx

            if current_length < min_length then
                min_length = current_length
            end
            last_idx = this_idx + 1
            this_idx = this_idx + 1
        end
    end
    if this_idx - last_idx < min_length then
        return this_idx - last_idx
    end
    return min_length
end

return find_short