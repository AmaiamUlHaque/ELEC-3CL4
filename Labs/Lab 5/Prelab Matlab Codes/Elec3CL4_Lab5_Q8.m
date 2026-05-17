%% Elec3CL4_Lab5_Q8
% using "Control System Toolbox"

s = tf('s');

% lab station plant transfer function
G = 311.8 / (s*(s+10.62));

% lab station controller transfer function
kc = 1.87;
z_lead = 13.33;
p_lead = 31.31;
z_lag = 0.1;
p_lag = 0.01;

% transfer functions
G_c_lead = kc * (s+z_lead)/(s+p_lead);
G_c_lag = (s+z_lag)/(s+p_lag);
G_c_lead_lag = G_c_lead * G_c_lag;

% closed loop transfer functions
T_lead = feedback(G_c_lead*G, 1);
T_lead_lag = feedback(G_c_lead_lag*G, 1);

% step response plots
figure
step(T_lead)
hold on
step(T_lead_lag)
legend('Lead', 'Lead-Lag')
grid on

% step response info
disp('Lead Compensator System:')
stepinfo(T_lead)
disp('Lead Compensator System:')
stepinfo(T_lead_lag)
