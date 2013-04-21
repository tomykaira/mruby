# from http://www.dzeta.jp/~junjis/code_reading/index.php?mruby%2F%A5%B9%A5%AF%A5%EA%A5%D7%A5%C8%B2%F2%C0%CF%A4%F2%C6%C9%A4%E0

module Test
  
end

# this overriding is ignored in mruby
class Float
  alias_method :orig, :*
  def *(x)
    p x
    orig(x)
  end
end

class MonteCarlo
  def pi(n)
    count = 0
    (1..n).each do
      x = rand
      y = rand
      if x * x + y * y <= 1
        count += 1
      end
    end
    (count.to_f / n) * 4
  end

  def test
    "hello"
  end
end

n = 10000 * 10000
pi = MonteCarlo.new.pi(10)
puts "pi = #{pi}"
# ~> -:34:in `<main>': uninitialized constant MonteCarlo (NameError)
