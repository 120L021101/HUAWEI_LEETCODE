function count_tested_devices(battery_percentages) 

    local count = 0

    for i = 1, #battery_percentages do
        if battery_percentages[i] > count then
            count = count + 1
        end
    end

    return count
end

input_arr = {1, 1, 2, 1, 3}
print(count_tested_devices(input_arr))

input_arr = {0, 1, 2}
print(count_tested_devices(input_arr))