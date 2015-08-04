package Raindrops;

use Scalar::Util;
use Carp;
use warnings;
use strict;
use Exporter;
use vars qw($VERSION @ISA @EXPORT @EXPORT_OK %EXPORT_TAGS);

$VERSION     = 1.00;
@ISA         = qw(Exporter);
@EXPORT      = ();
@EXPORT_OK   = qw(
    convert
);
%EXPORT_TAGS = ( DEFAULT => [qw(
    &convert
)],);


sub convert($) {
    my $num = shift(@_);
    my $response = "";

    if (!Scalar::Util::looks_like_number($num)) {
        croak("Input number $num is not a number!\n");
    }
    
    # - If the number contains 3 as a prime factor, output 'Pling'.
    #- If the number contains 5 as a prime factor, output 'Plang'.
    #- If the number contains 7 as a prime factor, output 'Plong'.
    #- If the number does not contain 3, 5, or 7 as a prime factor,
    #  just pass the number's digits straight through.
    
    if ($num % 3 == 0) {
        $response .= "Pling";
    }

    if ($num % 5 == 0) {
        $response .= "Plang";
    }
    
    if ($num % 7 == 0) {
        $response .= "Plong";
    }
    
    if ($response =~ m/^\s*$/) {
        $response = $num;
    }
    
    return $response;
}
