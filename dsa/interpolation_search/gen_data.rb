


def gen_data size
  file_name = "data_#{size}.txt"

  list = []
  File.open(file_name, 'w') do |f|
    size.times do |i|
      list[i] = Random.rand(size * 100)
    end

    list.sort!

    list.each do |e|
      f.puts e
    end
  end
end



gen_data 100
gen_data 1000
gen_data 10000
gen_data 100000
gen_data 1000000
