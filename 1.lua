function table2string(t)
    local ret = "{"
    for k, v in pairs(t) do
        ret = ret .. "\n" .. tostring(k) .. " " .. tostring(v)
    end
    ret = ret .. "\n}"
    return ret
end

function two_sum(nums, target)
    
    local occured = {}
    
    for i = 1, #nums do
        local find_val = target - nums[i]
        local prev_idx = occured[find_val]

        if prev_idx then
            return {prev_idx, i}
        end

        occured[nums[i]] = i
    end

    return nil
end

print(table2string(two_sum({2, 7, 11, 15}, 9)))
print(table2string(two_sum({3, 2, 4}, 6)))
print(table2string(two_sum({3, 3}, 6)))
