require 'rubygems'
require 'sinatra'

get '/' do
  x_start = request.env['HTTP_X_REQUEST_START']
  if x_start
    "X-Request-Start: #{x_start}"
  else
    "No X-Request-Start header found!"
  end
end

